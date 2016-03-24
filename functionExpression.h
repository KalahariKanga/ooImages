#pragma once
#include "Expression.h"
class functionExpression :
	public Expression
{
public:
	functionExpression();
	~functionExpression();
	virtual Variable evaluate();
	virtual Expression* acquire(std::vector<std::shared_ptr<Expression>>* tokens);
};

