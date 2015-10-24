#include "BinaryOperatorExpression.h"
#include <limits>

BinaryOperatorExpression::BinaryOperatorExpression(BinaryOperatorExpression::Operator op) : op(op)
{
	noArguments = 2;
}


BinaryOperatorExpression::~BinaryOperatorExpression()
{
}

Variable BinaryOperatorExpression::evaluate()
{
	Variable var(Variable::Type::Real);
	float a = *arguments[0]->evaluate().get<float>();
	float b = *arguments[1]->evaluate().get<float>();
	float v;
	switch (op)
	{
	case Operator::ADD:
		v = a + b;
		break;
	case Operator::SUBTRACT:
		v = a - b;
		break;
	case Operator::MULTIPLY:
		v = a * b;
		break;
	case Operator::DIVIDE:
		v = b == 0 ? std::numeric_limits<float>::infinity() : a / b;
		break;
	default:
		throw new Exception(Exception::ErrorType::ILLEGAL_OPERATOR);
	}
	var.set<float>(&v);
	return var;
}
