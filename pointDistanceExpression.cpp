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
	float x1 = arguments[0]->evaluate().real;
	float y1 = arguments[1]->evaluate().real;
	float x2 = arguments[2]->evaluate().real;
	float y2 = arguments[3]->evaluate().real;

	float distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	Variable var(Variable::Type::Real);
	var.real = distance;
	return var;
}