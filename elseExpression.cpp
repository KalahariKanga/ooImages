#include "elseExpression.h"


elseExpression::elseExpression()
{
	noArguments = 1;
	optimisable = 0;
}


elseExpression::~elseExpression()
{
}

Variable elseExpression::evaluate()
{
	return arguments[0]->getResult();
}