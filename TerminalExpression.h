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
	
	Variable evaluate();
	
};

