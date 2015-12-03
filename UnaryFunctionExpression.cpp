#include "UnaryFunctionExpression.h"


UnaryFunctionExpression::UnaryFunctionExpression(FunctionType fn) : function(fn)
{
	noArguments = 1;
}


UnaryFunctionExpression::~UnaryFunctionExpression()
{
}

Variable UnaryFunctionExpression::evaluate()
{
	float x = *arguments[0]->getResult().get<float>();
	float y = 0;
	switch (function)
	{
	case FunctionType::SIN:
		y = sin(x);
		break;
	default:
		throw new Exception(Exception::ErrorType::ILLEGAL_OPERATOR);
	}
	Variable var(Variable::Type::Real);
	var.set<float>(new float(y));
	return var;
}