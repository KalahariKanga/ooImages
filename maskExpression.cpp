#include "maskExpression.h"


maskExpression::maskExpression()
{
	noArguments = 1;
}


maskExpression::~maskExpression()
{
}

Variable maskExpression::evaluate()
{
	ImageStore* is = ImageStore::get();
	is->mask = arguments[0]->getResult().getShared<AbstractMask>();
	return Variable(Variable::Type::Void);
}
