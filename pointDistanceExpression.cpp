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
	float x1 = *arguments[0]->evaluate().get<float>();
	float y1 = *arguments[1]->evaluate().get<float>();
	float x2 = *arguments[2]->evaluate().get<float>();
	float y2 = *arguments[3]->evaluate().get<float>();

	float distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	Variable var(Variable::Type::Real);
	var.set<float>(new float(distance));
	return var;
}