#pragma once
#include "Expression.h"
class BinaryOperatorExpression :
	public Expression
{
public:
	enum class Operator
	{
		ADD, SUBTRACT, MULTIPLY, DIVIDE
	} op;
	BinaryOperatorExpression(Operator op);
	~BinaryOperatorExpression();
	virtual Variable evaluate();
};



