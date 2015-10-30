#pragma once
#include "TerminalExpression.h"
class ArrayVariableExpression :
	public TerminalExpression
{
	std::string string;
	VariableStore* vs;
public:
	ArrayVariableExpression(std::string string);
	~ArrayVariableExpression();
	virtual Variable evaluate();
	virtual std::string getName();
};

