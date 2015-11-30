#pragma once
#include "Expression.h"
#include "VariableStore.h"

class TerminalExpression :
	public Expression
{
protected:
	std::string string;
	VariableStore* vs = VariableStore::get();
	std::map<std::string, Variable> localVariables;
	std::map<std::string, float*> localRealPointers;
public:
	TerminalExpression() = default;
	TerminalExpression(std::string string);
	~TerminalExpression();
	
	virtual void setLocalVariable(std::string name, Variable ptr);
	virtual void setLocalVariable(std::string name, float* val);

	virtual bool calculateConstancy();
	Variable evaluate();
	virtual std::string getString();
	virtual std::string getName();
};

