#include "TerminalExpression.h"


TerminalExpression::TerminalExpression(std::string string) : string(string)
{
	noArguments = 0;
}


TerminalExpression::~TerminalExpression()
{
}

Variable TerminalExpression::evaluate()
{
	parser.setString(string);
	Variable var(Variable::Type::Real);
	var.real = parser.evaluate();
	return var;
}