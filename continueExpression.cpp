#include "continueExpression.h"
#include "ControlException.h"

continueExpression::continueExpression()
{
	noArguments = 0;
}


continueExpression::~continueExpression()
{
}

Variable continueExpression::evaluate()
{
	throw ControlException(ControlException::Type::CONTINUE);
}
