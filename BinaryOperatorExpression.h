#pragma once
#include "Expression.h"
class BinaryOperatorExpression :
	public Expression
{
public:
	enum class Operator
	{
		ADD, SUBTRACT, MULTIPLY, DIVIDE, EQUAL, LESS_EQUAL, GREATER_EQUAL, LESS, GREATER
	} op;
	BinaryOperatorExpression(Operator op);
	~BinaryOperatorExpression();
	virtual Variable evaluate();
};



