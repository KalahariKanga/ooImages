#include "imageExpression.h"


imageExpression::imageExpression()
{
	noArguments = 0;
}


imageExpression::~imageExpression()
{
}

Variable imageExpression::evaluate()
{
	Variable var;
	var.set(store->image);
	return var;
}