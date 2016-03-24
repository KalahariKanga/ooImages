#include "transformToExpression.h"

transformToExpression::transformToExpression()
{
	noArguments = 2;
}


transformToExpression::~transformToExpression()
{
}

void transformToExpression::drawQuadrilateral(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, Colour col)
{
	//find ymin and ymax
	int ymin = std::min({ y1, y2, y3, y4 });
	int ymax = std::max({ y1, y2, y3, y4 });
	int xmin = std::min({ x1, x2, x3, x4 });
	int xmax = std::max({ x1, x2, x3, x4 });

	if (xmin > buffer->getWidth() || xmax < 0)
		return;
	if (ymin > buffer->getHeight() || ymax < 0)
		return;

	std::vector<int> polyY = { y1, y2, y3, y4 };
	std::vector<int> polyX = { x1, x2, x3, x4 };

	for (int y = ymin; y < ymax; ++y)
	{
		int j = 3;
		std::vector<int> nodeX;
		for (int i = 0; i < 4; i++)
		{
			if (polyY[i] <= y && polyY[j] > y || polyY[j] <= y && polyY[i] > y)
			{
				nodeX.push_back((int)(polyX[i] + (float)(y - polyY[i]) / (polyY[j] - polyY[i]) * (polyX[j] - polyX[i])));
			}
			j = i;
		}

		std::sort(nodeX.begin(), nodeX.end());

		//  Fill the pixels between node pairs.
		for (int i = 0; i < nodeX.size(); i += 2)
		{
			if (nodeX[i] >= xmax) break;
			if (nodeX[i + 1] > xmin)
			{
				if (nodeX[i] < xmin) nodeX[i] = xmin;
				if (nodeX[i + 1] > xmax) nodeX[i + 1] = xmax;
				for (int x = nodeX[i]; x < nodeX[i + 1]; x++)
					buffer->setPixel(x, y, col);
			}
		}
	}
}

Variable transformToExpression::evaluate()
{
	setLocalVariable("r", &r);
	setLocalVariable("g", &g);
	setLocalVariable("b", &b);
	setLocalVariable("h", &h);
	setLocalVariable("s", &s);
	setLocalVariable("v", &v);
	setLocalVariable("a", &a);
	setLocalVariable("x", &x);
	setLocalVariable("y", &y);

	typedef std::vector<std::vector<std::pair<int, int>>> vectorField;
	vectorField pointLocation(image->getWidth() + 1, std::vector<std::pair<int, int>>(image->getHeight() + 1));

	for (int cx = 0; cx < image->getWidth()+1; cx++)
		for (int cy = 0; cy < image->getHeight()+1; cy++)
		{
			x = cx;
			y = cy;
			Colour p = image->getPixel(cx, cy);
			r = p.r();
			g = p.g();
			b = p.b();
			h = p.h();
			s = p.s();
			v = p.v();
			a = p.a();

			int xpos = (int)*arguments[0]->getResult().get<Real>();
			int ypos = (int)*arguments[1]->getResult().get<Real>();
			pointLocation[cx][cy] = std::make_pair(xpos, ypos);
		}
	
	for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
		{
			int tlX = std::get<0>(pointLocation[cx][cy]);
			int tlY = std::get<1>(pointLocation[cx][cy]);
			int trX = std::get<0>(pointLocation[cx + 1][cy]);
			int trY = std::get<1>(pointLocation[cx + 1][cy]);
			int brX = std::get<0>(pointLocation[cx + 1][cy + 1]);
			int brY = std::get<1>(pointLocation[cx + 1][cy + 1]);
			int blX = std::get<0>(pointLocation[cx][cy + 1]);
			int blY = std::get<1>(pointLocation[cx][cy + 1]);
			drawQuadrilateral(tlX, tlY, trX, trY, brX, brY, blX, blY, image->getPixel(cx,cy));
		}
	commitBuffer();
	return Variable();
}
