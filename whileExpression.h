#pragma once
#include "Expression.h"
class whileExpression :
	public Expression
{
public:
	whileExpression();
	~whileExpression();
	virtual Variable evaluate();
};

