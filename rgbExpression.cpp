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
	Colour col(*arguments[0]->getResult().get<float>(), *arguments[1]->getResult().get<float>(), *arguments[2]->getResult().get<float>());
	var.set<Colour>(new Colour(col));
	return var;
}