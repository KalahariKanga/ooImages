#pragma once
#include "Expression.h"
#include "VariableStore.h"

class TerminalExpression :
	public Expression
{
	std::string string;
	VariableStore* vs;
	std::map<std::string, float*> localVariables;
	enum class TerminalType
	{
		GLOBAL_VAR, LOCAL_VAR, REAL
	};
public:
	TerminalExpression() = default;
	TerminalExpression(std::string string);
	~TerminalExpression();
	
	virtual void addLocalVariable(std::string name, float* ptr);
	virtual bool calculateConstancy();
	Variable evaluate();
	virtual std::string getString();
	virtual std::string getName();
};

