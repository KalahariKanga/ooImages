#include "printExpression.h"
#include "Array.h"

printExpression::printExpression()
{
	noArguments = 1;
	optimisable = 0;
}


printExpression::~printExpression()
{
}

Variable printExpression::evaluate()
{
	auto result = arguments[0]->getResult();
	if (result.isType<Real>())
	{
		float value = *result.get<Real>();
		std::cout << value << std::endl;
	}
	
	if (result.isType<Array>())
	{
		auto arr = result.get<Array>();
		std::cout << "[ ";
		for (int c = 0; c < arr->size(); c++)
			std::cout << *arr->get(c).get<Real>() << " ";
		std::cout << "]\n";
	}

	return Variable();
}