#include "aboutExpression.h"


aboutExpression::aboutExpression()
{
	noArguments = 1;
}


aboutExpression::~aboutExpression()
{
}

Variable aboutExpression::evaluate()
{
	Variable result = arguments[0]->evaluate();
	if (result.isNull())
	{
		std::cout << "About\nVoid\n";
		return Variable();
	}

	auto resource = result.get<Resource>();
	if (!resource)
		throw new Exception(Exception::ErrorType::UNKNOWN_VARIABLE);
	resource->about();
	return Variable();
}
