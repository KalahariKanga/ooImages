#pragma once
#include "Expression.h"
#include "ExpressionParser.h"

class TerminalExpression :
	public Expression
{
	ExpressionParser parser;
	std::string string;
public:
	TerminalExpression(std::string string);
	~TerminalExpression();
	
	virtual void addLocalVariable(std::string name, float* ptr);

	Variable evaluate();
	
};

