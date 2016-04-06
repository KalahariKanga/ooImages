#include "variableExistsExpression.h"
#include "TerminalExpression.h"

variableExistsExpression::variableExistsExpression()
{
	noArguments = 1;
}


variableExistsExpression::~variableExistsExpression()
{
}

Variable variableExistsExpression::evaluate()
{
	std::string rawname;
	auto term = std::dynamic_pointer_cast<TerminalExpression>(arguments[0]);
	if (term)
	{
		rawname = term->getString();
	}
	else
		throw new Exception(Exception::ErrorType::ILLEGAL_NAME);

	if (VariableStore::get()->variableExists(rawname))
		return Variable(1.0);
	if (term->localVariableExists(rawname))
		return Variable(1.0);

	return Variable(0.0);
}
