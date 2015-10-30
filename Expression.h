#pragma once
#include "core.h"
#include "Variable.h"

class Expression
{

public:
	Expression();
	~Expression();

	virtual Expression* acquire(std::vector<Expression*>* tokens);
	virtual Variable evaluate() = 0;
	virtual void addLocalVariable(std::string name, float* ptr);
	std::vector<Expression*> arguments;
	virtual bool isConstant();
	int noArguments;
};

