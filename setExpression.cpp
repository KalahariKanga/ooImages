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
	
	//check if new variable name
	//TODO: check for illegal characters
	auto term = dynamic_pointer_cast<TerminalExpression>(arguments[0]);
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
		VariableStore::get()->setVariable(rawname, var);
	}
	else
		throw new Exception(Exception::ErrorType::ILLEGAL_NAME);

	return var;
}
