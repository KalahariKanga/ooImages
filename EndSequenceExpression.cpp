#include "EndSequenceExpression.h"


EndSequenceExpression::EndSequenceExpression()
{
	noArguments = 0;
}


EndSequenceExpression::~EndSequenceExpression()
{
}

Variable EndSequenceExpression::evaluate()
{
	return Variable(Variable::Type::Void);
}
