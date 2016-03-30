#pragma once
#include "Expression.h"
class UnaryFunctionExpression :
	public Expression
{
public:
	enum class FunctionType
	{
		SIN, COS, TAN, LOG, LN, EXP, ABS, FLOOR, SQRT
	} function;
	UnaryFunctionExpression(FunctionType fn);
	~UnaryFunctionExpression();
	
	virtual Variable evaluate();
};

