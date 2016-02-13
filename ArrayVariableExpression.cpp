#include "ArrayVariableExpression.h"


ArrayVariableExpression::ArrayVariableExpression(std::string string) : TerminalExpression(), string(string)
{
	noArguments = 1;
	vs = VariableStore::get();
	string.erase(string.end() - 1);
}


ArrayVariableExpression::~ArrayVariableExpression()
{
}

void ArrayVariableExpression::setLocalVariable(std::string name, Variable var)
{
	localVariables[name] = var;
	for (int c = 0; c < noArguments; c++)
		arguments[c]->setLocalVariable(name, var);
}
void ArrayVariableExpression::setLocalVariable(std::string name, float* ptr)
{
	localPointers[name] = ptr;
	for (int c = 0; c < noArguments; c++)
		arguments[c]->setLocalVariable(name, ptr);
}

Variable ArrayVariableExpression::evaluate()
{
	//think about when this needs to get called
	std::string name = getName();
	if (vs->variableExists(name))
		return VariableStore::get()->getVariable(name);
	throw new Exception(Exception::ErrorType::ARRAY_ERROR);
}

std::string ArrayVariableExpression::getName()
{
	std::string trimmed = string;
	trimmed.erase(trimmed.end()-1);
	int i = (int)round(*arguments[0]->getResult().get<Real>());
	std::string index = std::to_string(i);
	return index + trimmed;
}

std::string ArrayVariableExpression::getString()
{
	return string;
}