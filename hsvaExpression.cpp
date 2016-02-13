#include "hsvaExpression.h"


hsvaExpression::hsvaExpression()
{
	noArguments = 4;
}


hsvaExpression::~hsvaExpression()
{
}

Variable hsvaExpression::evaluate()
{
	Variable var(Variable::Type::Colour);
	Colour col;
	col.hsv(*arguments[0]->getResult().get<Real>(), *arguments[1]->getResult().get<Real>(), *arguments[2]->getResult().get<Real>());
	col.a(*arguments[3]->getResult().get<Real>());
	var.set<Colour>(new Colour(col));
	return var;
}