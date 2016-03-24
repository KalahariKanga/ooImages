#pragma once
#include "Expression.h"
class ifExpression :
	public Expression
{
	bool hasElse = 0;
public:
	ifExpression();
	~ifExpression();
	virtual Variable evaluate();

	virtual Expression* acquire(std::vector<std::shared_ptr<Expression>>* tokens);

};

