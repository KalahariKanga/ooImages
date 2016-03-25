#pragma once
#include "core.h"
#include "Variable.h"
#include "ImageStore.h"

class Expression
{
	Variable constantValue;
	bool hasConstantValue = 0;
	
protected:
	bool isConstant = 0;
	bool optimisable = 1;
	static ImageStore* const store;
	std::map<std::string, Variable> localVariables;
	std::map<std::string, float*> localPointers;
	
public:
	Expression();
	~Expression();
	Expression* parent = nullptr;
	static const bool constancyOptimisation = 1;

	virtual Expression* acquire(std::vector<std::shared_ptr<Expression>>* tokens);
	Variable getResult();
	virtual Variable evaluate() = 0;
	virtual void setLocalVariable(std::string name, Variable var);
	virtual void setLocalVariable(std::string name, float* ptr);
	virtual Variable getLocalVariable(std::string name);
	bool localVariableExists(std::string name);

	std::vector<std::shared_ptr<Expression>> arguments;
	virtual bool calculateConstancy();
	int noArguments;
};

