#include "fuzzyExpression.h"


fuzzyExpression::fuzzyExpression()
{
	noArguments = 3;
}


fuzzyExpression::~fuzzyExpression()
{
}

Variable fuzzyExpression::evaluate()
{
	ImageObject* image = store->getImage();
	Variable var(new Mask(image->getWidth(), image->getHeight()));
	auto selection = var.get<Mask>();
	selection->invert();
	int sx = static_cast<int>(*arguments[0]->getResult().get<Real>());
	int sy = static_cast<int>(*arguments[1]->getResult().get<Real>());
	float dist = *arguments[2]->getResult().get<Real>();

	Colour col = image->getPixel(sx, sy);

	//queue of pixels to check next
	std::queue<std::pair<int,int>> Q;
	//array of pixels already checked
	std::vector<std::vector<int>> processed(image->getWidth(), vector<int>(image->getHeight(), 0));
	Q.push(std::make_pair(sx,sy));
	while (!Q.empty())
	{
		
		auto n = Q.front();
		Q.pop();
		int x = n.first;
		int y = n.second;
		Colour newCol = image->getPixel(x, y);
		if (Colour::distance(col, newCol) <= dist && !processed[x][y]) //not 100% why i need the !proc bit
		{
			selection->setValue(x, y, 1);
			processed[x][y] = 1;
			if (x > 0 && !processed[x - 1][y])
				Q.push(std::make_pair(x - 1, y));
			if (x < image->getWidth() - 1 && !processed[x + 1][y])
				Q.push(std::make_pair(x + 1, y));
			if (y > 0 && !processed[x][y - 1])
				Q.push(std::make_pair(x, y - 1));
			if (y < image->getHeight() - 1 && !processed[x][y + 1])
				Q.push(std::make_pair(x, y + 1));
		}
	}
	return var;
}
