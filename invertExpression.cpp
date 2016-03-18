#include "invertExpression.h"


invertExpression::invertExpression()
{
	noArguments = 1;
}


invertExpression::~invertExpression()
{
}

Variable invertExpression::evaluate()
{
	auto mask = arguments[0]->getResult().get<Mask>();
	mask->invert();
	return Variable();
}
