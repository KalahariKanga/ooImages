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
};

