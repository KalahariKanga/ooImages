#pragma once
#include "Expression.h"
#include "VariableStore.h"
#include "TerminalExpression.h"
class setExpression :
	public Expression
{
public:
	setExpression();
	~setExpression();
	virtual Variable evaluate();
};

