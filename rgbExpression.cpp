#include "rgbExpression.h"


rgbExpression::rgbExpression()
{
	noArguments = 3;
}


rgbExpression::~rgbExpression()
{
}

Variable rgbExpression::evaluate()
{
	Variable var(Variable::Type::Colour);
	var.colour = new Colour(arguments[0]->evaluate().real, arguments[1]->evaluate().real, arguments[2]->evaluate().real);
	return var;
}