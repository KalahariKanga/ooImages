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
}
