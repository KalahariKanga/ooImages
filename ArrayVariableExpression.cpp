#include "ArrayVariableExpression.h"


ArrayVariableExpression::ArrayVariableExpression(std::string string) : TerminalExpression(), string(string)
{
	noArguments = 1;
	vs = VariableStore::get();
	this->string.erase(this->string.end() - 1);
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
		var =  getLocalVariable(string);

	auto arr = var.get<Array>();
	return arr->get((int)round(*arguments[0]->getResult().get<Real>()));

	//throw new Exception(Exception::ErrorType::ARRAY_ERROR);
}

std::string ArrayVariableExpression::getName()
{
	return string;
}

std::string ArrayVariableExpression::getString()
{
	return string;
}

int ArrayVariableExpression::getIndex()
{
	return (int)round(*arguments[0]->getResult().get<Real>());
}