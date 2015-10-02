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
	Colour col(*arguments[0]->evaluate().get<float>(), *arguments[1]->evaluate().get<float>(), *arguments[2]->evaluate().get<float>());
	var.set<Colour>(new Colour(col));
	return var;
}