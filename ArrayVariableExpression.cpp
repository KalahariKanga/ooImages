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
	std::string index = std::to_string((int)round(*arguments[0]->evaluate().get<float>()));
	return index + trimmed;
}