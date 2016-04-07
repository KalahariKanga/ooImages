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

Variable TerminalExpression::evaluate()
{
	//local variable
	auto exp = localVariableExists(string);
	if (exp)
		return exp->getLocalVariable(string);
	
	//global variable
	if (vs->variableExists(string))
		return vs->getVariable(string);
	
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