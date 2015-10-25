#pragma once
#include "Expression.h"
#include "VariableStore.h"

class TerminalExpression :
	public Expression
{
	std::string string;
	VariableStore* vs;
	std::map<std::string, float*> localVariables;
public:
	TerminalExpression(std::string string);
	~TerminalExpression();
	
	virtual void addLocalVariable(std::string name, float* ptr);

	Variable evaluate();
	std::string getString();
};

