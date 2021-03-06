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
	float a = *arguments[0]->getResult().get<Real>();
	float b = *arguments[1]->getResult().get<Real>();
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
	case Operator::EQUAL:
		v = (a == b);//delta?
		break;
	case Operator::LESS_EQUAL:
		v = (a <= b);
		break;
	case Operator::GREATER_EQUAL:
		v = (a >= b);
		break;
	case Operator::LESS:
		v = (a < b);
		break;
	case Operator::GREATER:
		v = (a > b);
		break;
	case Operator::MOD:
		v = (float)((int)a % (int)b);
		break;
	case Operator::AND: //these could be problematic cos floats :/
		v = (a && b);
		break;
	case Operator::OR:
		v = (a || b);
		break;
	case Operator::POW:
		v = pow(a, b);
		break;
	default:
		throw new Exception(Exception::ErrorType::ILLEGAL_OPERATOR);
	}
	return Variable(v);
}
