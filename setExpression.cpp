#include "setExpression.h"

setExpression::setExpression()
{
	noArguments = 2;
}


setExpression::~setExpression()
{

}

Variable setExpression::evaluate()
{
	Variable var;
	std::string rawname, basename;
	//for normal variables, rawname == basename
	//for arrays, rawname = index##basename

	//TODO: check for illegal characters
	auto term = std::dynamic_pointer_cast<TerminalExpression>(arguments[0]);
	if (term)
	{
		rawname = term->getName();
		basename = term->getString();
	}
	else
		throw new Exception(Exception::ErrorType::ILLEGAL_NAME);

	if (VariableStore::get()->legalVariableName(basename))
	{
		var = arguments[1]->getResult().duplicate();
		if (parent)
			parent->setLocalVariable(rawname, var);
		else
			VariableStore::get()->setVariable(rawname, var);
	}
	else
		throw new Exception(Exception::ErrorType::ILLEGAL_NAME);

	return var;
}
