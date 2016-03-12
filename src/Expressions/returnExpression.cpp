#include "returnExpression.h"


returnExpression::returnExpression()
{
	noArguments = 1;
	optimisable = 0;
}


returnExpression::~returnExpression()
{
}

Variable returnExpression::evaluate()
{
	//i really can't think of a better way of unwinding the stack...
	Variable var = arguments[0]->evaluate();
	throw var;
}
