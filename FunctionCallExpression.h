#pragma once
#include "TerminalExpression.h"
#include "Function.h"

class FunctionCallExpression :
	public TerminalExpression
{
	std::string string; //careful
public:
	FunctionCallExpression(std::string name);
	~FunctionCallExpression();
	virtual Variable evaluate();

	virtual Expression* acquire(std::vector<std::shared_ptr<Expression>>* tokens);
};

