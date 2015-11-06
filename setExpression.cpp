#include "setExpression.h"
#include "VariableExpression.h"

setExpression::setExpression()
{
	noArguments = 2;
}


setExpression::~setExpression()
{

}

Variable setExpression::evaluate()
{
	std::string name;
	
	//check if new variable name
	//TODO: check for illegal characters
	TerminalExpression* term = dynamic_cast<TerminalExpression*>(arguments[0]);
	if (term)
		name = term->getName();
	else
		throw new Exception(Exception::ErrorType::ILLEGAL_NAME);

	if (VariableStore::get()->legalVariableName(name))
	{
		Variable var = arguments[1]->getResult().duplicate();
		VariableStore::get()->setVariable(name, var);
	}
	else
		throw new Exception(Exception::ErrorType::ILLEGAL_NAME);

	return Variable(Variable::Type::Void);
}