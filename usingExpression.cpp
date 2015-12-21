#include "usingExpression.h"
#include "ImageStore.h"
#include "TerminalExpression.h"

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
	auto term = dynamic_pointer_cast<TerminalExpression>(arguments[0]);
	if (term)
	{
		Variable image = VariableStore::get()->getRawVariable(term->getString());
		is->image = image.getShared<ImageObject>();
	}
	else
		is->image = arguments[0]->getResult().getShared<ImageObject>();
	return Variable(Variable::Type::Void);

}
