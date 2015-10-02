#include "TerminalExpression.h"


TerminalExpression::TerminalExpression(std::string string) : string(string)
{
	noArguments = 0;
	parser.setString(string);
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
	Variable var(Variable::Type::Real);
	var.set<float>(new float(parser.evaluate()));
	return var;
}