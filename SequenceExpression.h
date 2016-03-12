#pragma once
#include "Expression.h"
class SequenceExpression :
	public Expression
{
public:
	SequenceExpression();
	~SequenceExpression();
	virtual Variable evaluate();
	virtual Expression* acquire(std::vector<shared_ptr<Expression>>* tokens);
};

