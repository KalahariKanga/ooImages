#include "TerminalExpression.h"


TerminalExpression::TerminalExpression(std::string string) : string(string)
{
	noArguments = 0;
	parser.setString(string);
	vs = VariableStore::get();
}


TerminalExpression::~TerminalExpression()
{
}

void TerminalExpression::addLocalVariable(std::string name, float* ptr)
{
	parser.addLocalVariable(name, ptr);
}

Variable TerminalExpression::evaluate()
{
	
	if (vs->variableExists(string))
		return VariableStore::get()->getVariable(string);

	Variable var(Variable::Type::Real);
	var.set<float>(new float(parser.evaluate()));
	return var;
}

std::string TerminalExpression::getString()
{
	return string;
}