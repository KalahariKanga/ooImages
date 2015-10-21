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
	col.hsv(*arguments[0]->evaluate().get<float>(), *arguments[1]->evaluate().get<float>(), *arguments[2]->evaluate().get<float>());
	col.a(*arguments[3]->evaluate().get<float>());
	var.set<Colour>(new Colour(col));
	return var;
}