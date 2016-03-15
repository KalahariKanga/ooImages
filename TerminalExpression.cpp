#include "TerminalExpression.h"


TerminalExpression::TerminalExpression(std::string string) : string(string)
{
	noArguments = 0;
	vs = VariableStore::get();
}


TerminalExpression::~TerminalExpression()
{
}

bool TerminalExpression::calculateConstancy()
{
	try
	{
		float val = stof(string);
	}
	catch (std::invalid_argument)
	{
		isConstant = 0;
		return 0;
	}
	isConstant = 1;
	return 1;
}

void TerminalExpression::setLocalVariable(std::string name, Variable var)
{
	//check for conflicts
	localVariables[name] = var;
}

void TerminalExpression::setLocalVariable(std::string name, float* val)
{
	//check for conflicts
	localPointers[name] = val;
}

bool TerminalExpression::localVariableExists(std::string name)
{
	if (localVariables.find(string) != localVariables.end())
		return 1;
	if (localPointers.find(string) != localPointers.end())
		return 1;
	return 0;
}

Variable TerminalExpression::evaluate()
{
	//resource variable
	if (vs->variableExists(string))
		return VariableStore::get()->getVariable(string);

	//local variable
	if (localVariables.find(string) != localVariables.end())
	{
		return localVariables[string];
	}

	//local ptr
	if (localPointers.find(string) != localPointers.end())
	{
		Variable var(*localPointers[string]);
		return var;
	}
	
	//constant
	try
	{
		float val = stof(string);
		return Variable(val);
	}
	catch (std::invalid_argument)
	{
		throw new Exception(Exception::ErrorType::PARSER_ERROR);
	}
}

std::string TerminalExpression::getString()
{
	return string;
}

std::string TerminalExpression::getName()
{
	return string;
	//TODO: check that it is a named variable
}