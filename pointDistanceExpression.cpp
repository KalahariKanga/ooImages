#include "pointDistanceExpression.h"


pointDistanceExpression::pointDistanceExpression()
{
	noArguments = 4;
}


pointDistanceExpression::~pointDistanceExpression()
{
}

Variable pointDistanceExpression::evaluate()
{
	float x1 = *arguments[0]->getResult().get<Real>();
	float y1 = *arguments[1]->getResult().get<Real>();
	float x2 = *arguments[2]->getResult().get<Real>();
	float y2 = *arguments[3]->getResult().get<Real>();

	float distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	return Variable(distance);
}