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
	virtual std::string getString();

	virtual void setLocalVariable(std::string name, Variable var);
	//virtual void setLocalVariable(std::string name, Resource* ptr);
};

