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
		name = term->getString();

	Variable var = arguments[1]->evaluate().duplicate();
	VariableStore::get()->setVariable(name, var);

	//keep expressionparser updated...
	if (var.type == Variable::Type::Real)
		ExpressionParser::updateVariable(name, *var.get<float>());

	//std::cout << name << " " << *var.get<float>() << "\n";
	return Variable(Variable::Type::Void);
}