#include "TerminalExpression.h"


TerminalExpression::TerminalExpression(std::string string) : string(string)
{
	noArguments = 0;
	vs = VariableStore::get();
}


TerminalExpression::~TerminalExpression()
{
}

void TerminalExpression::addLocalVariable(std::string name, float* ptr)
{
	localVariables[name] = ptr;
}

Variable TerminalExpression::evaluate()
{
	
	if (vs->variableExists(string))
		return VariableStore::get()->getVariable(string);

	
	if (localVariables.find(string) != localVariables.end())
	{
		Variable var(Variable::Type::Real);
		var.set<float>(localVariables[string]);
		return var;
	}
	
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