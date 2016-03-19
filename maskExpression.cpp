#include "maskExpression.h"


maskExpression::maskExpression()
{
	noArguments = 0;
}


maskExpression::~maskExpression()
{
}

Variable maskExpression::evaluate()
{
	Variable var;
	var.set(store->mask);
	return var;
}
