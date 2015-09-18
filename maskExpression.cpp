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
	delete is->mask;
	is->mask = arguments.back()->evaluate().moveMask();
	return Variable(Variable::Type::Void);
}
