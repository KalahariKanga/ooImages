#include "usingExpression.h"
#include "ImageStore.h"

usingExpression::usingExpression()
{
	noArguments = 1;
}


usingExpression::~usingExpression()
{
}

Variable usingExpression::evaluate()
{
	ImageStore* is = ImageStore::get();
	is->image = arguments[0]->getResult().getShared<ImageObject>();
	return Variable(Variable::Type::Void);

}
