#include "repeatExpression.h"


repeatExpression::repeatExpression()
{
	noArguments = 2;
}


repeatExpression::~repeatExpression()
{
}

Variable repeatExpression::evaluate()
{
	int n = (int)(*arguments[0]->getResult().get<float>());
	for (int c = 0; c < n; c++)
		arguments[1]->getResult();
	return Variable(Variable::Type::Void);
}
