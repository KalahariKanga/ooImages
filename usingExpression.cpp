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
	is->image = std::static_pointer_cast<ImageObject>(arguments[0]->evaluate().data);
	return Variable(Variable::Type::Void);

}
