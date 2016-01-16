#include "breakExpression.h"
#include "ControlException.h"

breakExpression::breakExpression()
{
	noArguments = 0;
}


breakExpression::~breakExpression()
{
}

Variable breakExpression::evaluate()
{
	throw ControlException(ControlException::Type::BREAK);
}