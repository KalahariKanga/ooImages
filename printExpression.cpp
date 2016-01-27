#include "printExpression.h"


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
	float value = *arguments[0]->getResult().get<float>();
	std::cout << value << std::endl;
	return Variable(Variable::Type::Void);
}