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

	Variable v = arguments.back()->getResult();
	if (v.type == Variable::Type::Mask)
	{
		is->mask = arguments[0]->getResult().getShared<Mask>();
	}
	else
		throw new Exception(Exception::ErrorType::TYPE_MISMATCH);

	return Variable(Variable::Type::Void);
}
