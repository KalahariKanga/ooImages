#pragma once
#include "TerminalExpression.h"


class FunctionCallExpression :
	public TerminalExpression
{
	std::string name;
public:
	FunctionCallExpression(std::string name);
	~FunctionCallExpression();
	virtual Variable evaluate();

	//reimplement to pass to arg list too
	virtual void setLocalVariable(std::string name, Variable var);
	virtual void setLocalVariable(std::string name, float* ptr);

	virtual Expression* acquire(std::vector<shared_ptr<Expression>>* tokens);
};

