#pragma once
#include "Expression.h"
#include "VariableStore.h"

class TerminalExpression :
	public Expression
{
protected:
	std::string string;
	VariableStore* vs = VariableStore::get();
	Expression* lastExpression = nullptr;
public:
	TerminalExpression() = default;
	TerminalExpression(std::string string);
	~TerminalExpression();

	virtual bool calculateConstancy();
	Variable evaluate();
	virtual std::string getString();
};

