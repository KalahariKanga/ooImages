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
	float x1 = arguments[0]->evaluate().real;
	float y1 = arguments[1]->evaluate().real;
	float x2 = arguments[2]->evaluate().real;
	float y2 = arguments[3]->evaluate().real;

	float direction = atan2(y2 - y1, x2 - x1);
	Variable var(Variable::Type::Real);
	var.real = 180*direction/PI;
	return var;
}