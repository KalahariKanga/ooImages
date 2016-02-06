#include "rgbaExpression.h"


rgbaExpression::rgbaExpression()
{
	noArguments = 4;
}


rgbaExpression::~rgbaExpression()
{
}

Variable rgbaExpression::evaluate()
{
	Variable var(Variable::Type::Colour);
	Colour col(*arguments[0]->getResult().get<Real>(), *arguments[1]->getResult().get<Real>(), *arguments[2]->getResult().get<Real>(), *arguments[3]->getResult().get<Real>());
	var.set<Colour>(new Colour(col));
	return var;
}
