#pragma once
#include "Expression.h"
#include "VariableStore.h"

class TerminalExpression :
	public Expression
{
	std::string string;
	VariableStore* vs;
	std::map<std::string, Variable> localVariables;
	std::map<std::string, float*> localRealPointers;
	enum class TerminalType
	{
		GLOBAL_VAR, LOCAL_VAR, REAL
	};
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

