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
	localVariables[name] = var;
}

void TerminalExpression::setLocalVariable(std::string name, float val)
{
	//optimisable?
	Variable var(Variable::Type::Real);
	var.set<float>(new float(val));
	localVariables[name] = var;
}

Variable TerminalExpression::evaluate()
{
	//resource variable
	if (vs->variableExists(string))
		return VariableStore::get()->getVariable(string);

	//local variable
	if (localVariables.find(string) != localVariables.end())
	{
		if (localVariables.find(string) != localVariables.end())
			return localVariables[string];
		else
			throw new Exception(Exception::ErrorType::UNKNOWN_VARIABLE);
	}
	
	//constant
	try
	{
		Variable var(Variable::Type::Real);
		float val = stof(string);
		var.set<float>(&val);
		return var;
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