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
	Variable var(Variable::Type::Image);
	var.set(new ImageObject());
	TerminalExpression* t = dynamic_cast<TerminalExpression*>(arguments[0]);
	if (t)
		var.get<ImageObject>()->loadImage(t->getString());
	else
		throw new Exception(Exception::ErrorType::TYPE_MISMATCH);
	return var;
}
