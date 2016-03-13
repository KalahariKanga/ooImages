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
	auto term = dynamic_pointer_cast<TerminalExpression>(arguments[0]);
	//be careful if its a local variable
	//or function call
	if (term)
	{
		Variable image = VariableStore::get()->getRawVariable(term->getName());
		store->image = image.getShared<ImageObject>();
	}
	else
		store->image = arguments[0]->getResult().getShared<ImageObject>();
	return Variable();

}
