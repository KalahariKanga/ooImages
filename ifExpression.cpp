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
	//TODO: reevaluate even if constant?
	if (*arguments[0]->getResult().get<float>())
	{
		arguments[1]->getResult();
	}
	return Variable(Variable::Type::Void);
}