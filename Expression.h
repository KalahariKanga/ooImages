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

	virtual Expression* acquire(std::vector<Expression*>* tokens);
	Variable getResult();
	virtual Variable evaluate() = 0;
	virtual void addLocalVariable(std::string name, float* ptr);
	std::vector<Expression*> arguments;
	virtual bool calculateConstancy();
	int noArguments;
};

