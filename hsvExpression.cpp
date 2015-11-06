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
	Colour col;
	col.hsv(*arguments[0]->getResult().get<float>(), *arguments[1]->getResult().get<float>(), *arguments[2]->getResult().get<float>());
	var.set<Colour>(new Colour(col));
	return var;
}