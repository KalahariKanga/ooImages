#include "saveImageExpression.h"
#include "TerminalExpression.h"
#include "ImageStore.h"

saveImageExpression::saveImageExpression()
{
	noArguments = 1;
}


saveImageExpression::~saveImageExpression()
{
}

Variable saveImageExpression::evaluate()
{
	std::string fname;
	auto term = std::dynamic_pointer_cast<TerminalExpression>(arguments[0]);
	if (term)
		fname = term->getString();
	else
		throw new Exception(Exception::ErrorType::ILLEGAL_NAME);
	store->getImage()->saveImage(fname);
	return Variable();
}
