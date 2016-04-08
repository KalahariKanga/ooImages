#include "arrayExpression.h"
#include "SequenceExpression.h"

arrayExpression::arrayExpression()
{
	noArguments = 1;
}


arrayExpression::~arrayExpression()
{
}

Variable arrayExpression::evaluate()
{
	auto sequence = std::dynamic_pointer_cast<SequenceExpression>(arguments[0]);

	if (!sequence)
		throw new Exception(Exception::ErrorType::MISMATCHED_BRACKETS);

	int elements = sequence->noArguments;
	Variable var(new Array());
	auto a = var.get<Array>();

	for (int c = 0; c < elements; c++)
	{
		a->set(c, sequence->arguments[c]->getResult());
	}
	return var;
}
