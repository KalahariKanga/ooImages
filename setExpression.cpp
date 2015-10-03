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
	std::string name;
	try
	{
		//TODO: check for illegal characters
		name = dynamic_cast<TerminalExpression*>(arguments[0])->getString();
	}
	catch (std::bad_cast)
	{
		std::cout << "Error: Illegal variable name\n";
		return Variable(Variable::Type::Void);
	}
	Variable var = arguments[1]->evaluate().duplicate();
	VariableStore::get()->setVariable(name, var);
	return Variable(Variable::Type::Void);
}