#include "ifExpression.h"


ifExpression::ifExpression()
{
	noArguments = 2;
}


ifExpression::~ifExpression()
{
}

Variable ifExpression::evaluate()
{
	if (*arguments[0]->evaluate().get<float>())
	{
		arguments[1]->evaluate();
	}
	return Variable(Variable::Type::Void);
}