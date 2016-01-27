#pragma once
#include "Expression.h"
class elseExpression :
	public Expression
{
public:
	elseExpression();
	~elseExpression();
	virtual Variable evaluate();
};

