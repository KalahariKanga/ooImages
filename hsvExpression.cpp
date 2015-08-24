#include "hsvExpression.h"


hsvExpression::hsvExpression()
{
	noArguments = 3;
}


hsvExpression::~hsvExpression()
{
}

Variable hsvExpression::evaluate()
{
	Variable var(Variable::Type::Colour);
	var.colour = new Colour();
	var.colour->hsv(arguments[0]->evaluate().real, arguments[1]->evaluate().real, arguments[2]->evaluate().real);
	return var;
}