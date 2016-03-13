#include "selectExpression.h"


selectExpression::selectExpression()
{
	noArguments = 1;
}


selectExpression::~selectExpression()
{
}

Variable selectExpression::evaluate()
{
	store->mask = arguments[0]->getResult().getShared<Mask>();
	return Variable();
}
