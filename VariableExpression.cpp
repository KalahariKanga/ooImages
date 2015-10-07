#include "VariableExpression.h"


VariableExpression::VariableExpression(std::string string) : string(string)
{
	noArguments = 0;
}


VariableExpression::~VariableExpression()
{
}

Variable VariableExpression::evaluate()
{
	return VariableStore::get()->getVariable(string);
}

std::string VariableExpression::getString()
{
	return string;
}