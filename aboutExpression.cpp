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
	if (result.type == Variable::Type::Real)
	{
		std::cout << "About\nReal\n";
		std::cout << *result.get<Real>();
		return Variable(Variable::Type::Void);
	}
	if (result.type == Variable::Type::Void)
	{
		std::cout << "About\nVoid\n";
		return Variable(Variable::Type::Void);
	}

	//so the variable hasa resource type
	auto resource = result.get<Resource>();
	if (!resource)
		throw new Exception(Exception::ErrorType::UNKNOWN_VARIABLE);
	resource->about();
	return Variable(Variable::Type::Void);
}
