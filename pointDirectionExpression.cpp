#include "pointDirectionExpression.h"


pointDirectionExpression::pointDirectionExpression()
{
	noArguments = 4;
}


pointDirectionExpression::~pointDirectionExpression()
{
}

Variable pointDirectionExpression::evaluate()
{
	float x1 = *arguments[0]->getResult().get<float>();
	float y1 = *arguments[1]->getResult().get<float>();
	float x2 = *arguments[2]->getResult().get<float>();
	float y2 = *arguments[3]->getResult().get<float>();

	float direction = atan2(y2 - y1, x2 - x1);
	Variable var(Variable::Type::Real);
	var.set<float>(new float(180*direction/PI));
	return var;
}