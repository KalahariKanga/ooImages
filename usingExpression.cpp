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
	store->image = arguments[0]->getResult().getShared<ImageObject>();
	store->mask->resize(store->image->getWidth(), store->image->getHeight());
	return Variable();
}
