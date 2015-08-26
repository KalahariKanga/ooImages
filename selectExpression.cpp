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
	ImageStore* is = ImageStore::get();
	delete is->mask;
	is->mask = arguments.back()->evaluate().mask;
}
