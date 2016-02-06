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
	float x = *arguments[0]->getResult().get<Real>();
	float y = 0;
	switch (function)
	{
	case FunctionType::SIN:
		y = sin(x);
		break;
	case FunctionType::COS:
		y = cos(x);
		break;
	case FunctionType::TAN:
		y = tan(x);
		break;
	case FunctionType::LN:
		y = log(x);
		break;
	case FunctionType::LOG:
		y = log10(x);
		break;
	case FunctionType::EXP:
		y = exp(x);
		break;
	default:
		throw new Exception(Exception::ErrorType::ILLEGAL_OPERATOR);
	}
	Variable var(Variable::Type::Real);
	var.set<float>(new float(y));
	return var;
}
