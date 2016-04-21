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
	if (lastExpression)
		var = lastExpression->getLocalVariable(string);
	else
	{
		lastExpression = localVariableExists(string);
		if (lastExpression)
			var = lastExpression->getLocalVariable(string);
	}
	
	if (vs->variableExists(string))
		var = VariableStore::get()->getVariable(string);

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