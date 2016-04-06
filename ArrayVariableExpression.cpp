#include "ArrayVariableExpression.h"


ArrayVariableExpression::ArrayVariableExpression(std::string str) : TerminalExpression(), string(str)
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
	Variable var;
	if (vs->variableExists(string))
		var = VariableStore::get()->getVariable(string);
	if (localVariableExists(string))
		var = getLocalVariable(string);

	auto arr = var.get<Array>();
	return arr->get(getIndex());
}

std::string ArrayVariableExpression::getString()
{
	return string;
}

int ArrayVariableExpression::getIndex()
{
	return (int)round(*arguments[0]->getResult().get<Real>());
}