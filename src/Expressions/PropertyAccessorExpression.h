#pragma once
#include "TerminalExpression.h"

class PropertyAccessorExpression :
	public TerminalExpression
{
	std::string varName;
public:
	PropertyAccessorExpression(std::string varName);
	~PropertyAccessorExpression();
	virtual Variable evaluate();
};

