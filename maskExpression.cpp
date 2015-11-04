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
	is->mask = std::static_pointer_cast<AbstractMask>(arguments[0]->getResult().data);
	return Variable(Variable::Type::Void);
}
