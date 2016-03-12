#pragma once
#include "Expression.h"
class EndSequenceExpression :
	public Expression
{
public:
	EndSequenceExpression();
	~EndSequenceExpression();
	virtual Variable evaluate();
};

