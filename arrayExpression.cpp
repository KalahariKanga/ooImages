#include "arrayExpression.h"


arrayExpression::arrayExpression()
{
	noArguments = 0;
}


arrayExpression::~arrayExpression()
{
}

Variable arrayExpression::evaluate()
{
	return Variable(new Array());
}
