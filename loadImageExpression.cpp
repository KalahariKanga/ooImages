#include "loadImageExpression.h"
#include "TerminalExpression.h"

loadImageExpression::loadImageExpression()
{
	noArguments = 1;
}


loadImageExpression::~loadImageExpression()
{
}

Variable loadImageExpression::evaluate()
{
	Variable var(new ImageObject());
	std::shared_ptr<TerminalExpression> t = dynamic_pointer_cast<TerminalExpression>(arguments[0]);
	if (t)
	{
		ImageObject* im = var.get<ImageObject>();
		im->loadImage(t->getString());
	}
	else
		throw new Exception(Exception::ErrorType::TYPE_MISMATCH);
	return var;
}
