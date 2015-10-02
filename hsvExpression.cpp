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
	col.hsv(*arguments[0]->evaluate().get<float>(), *arguments[1]->evaluate().get<float>(), *arguments[2]->evaluate().get<float>());
	var.set<Colour>(new Colour(col));
	return var;
}