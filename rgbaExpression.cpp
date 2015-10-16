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
	Colour col(*arguments[0]->evaluate().get<float>(), *arguments[1]->evaluate().get<float>(), *arguments[2]->evaluate().get<float>(), *arguments[3]->evaluate().get<float>());
	var.set<Colour>(new Colour(col));
	return var;
}
