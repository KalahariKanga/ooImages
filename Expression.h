#pragma once
#include "core.h"
#include "Variable.h"

class Expression
{
	Variable constantValue;
	bool hasConstantValue = 0;
	
protected:
	bool isConstant = 0;
	bool optimisable = 1;
public:
	Expression();
	~Expression();

	static const bool constancyOptimisation = 1;

	virtual Expression* acquire(std::vector<shared_ptr<Expression>>* tokens);
	Variable getResult();
	virtual Variable evaluate() = 0;
	virtual void setLocalVariable(std::string name, Variable var);
	//virtual void setLocalVariable(std::string name, Resource* val);
	std::vector<shared_ptr<Expression>> arguments;
	virtual bool calculateConstancy();
	int noArguments;
};

