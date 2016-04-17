#pragma once
#include "TerminalExpression.h"

class PropertyAccessorExpression :
	public TerminalExpression
{
	std::string name;
public:
	PropertyAccessorExpression(std::string varName);
	~PropertyAccessorExpression();
	virtual Variable evaluate();
};

