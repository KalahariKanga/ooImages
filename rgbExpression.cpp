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
	Colour col(*arguments[0]->getResult().get<Real>(), *arguments[1]->getResult().get<Real>(), *arguments[2]->getResult().get<Real>());
	Variable var(new Colour(col));
	return var;
}