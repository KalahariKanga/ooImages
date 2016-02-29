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

	std::vector<int> polyY = { y1, y2, y3, y4 };
	std::vector<int> polyX = { x1, x2, x3, x4 };

	for (int y = ymin; y <= ymax; ++y)
	{
		int j = 3;
		std::vector<int> nodeX;
		for (int i = 0; i < 4; i++)
		{
			if (polyY[i] < y && polyY[j] >= y || polyY[j] < y && polyY[i] >= y)
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


	commitBuffer();
	return Variable();
}
