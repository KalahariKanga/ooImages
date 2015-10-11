#pragma once
#include "Expression.h"
#include "ExpressionParser.h"
#include "VariableStore.h"

class TerminalExpression :
	public Expression
{
	ExpressionParser parser;
	std::string string;
	VariableStore* vs;
public:
	TerminalExpression(std::string string);
	~TerminalExpression();
	
	virtual void addLocalVariable(std::string name, float* ptr);

	Variable evaluate();
	std::string getString();
};

