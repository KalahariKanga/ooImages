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
	Variable var(new Array());
	auto a = var.get<Array>();

	auto sequence = std::dynamic_pointer_cast<SequenceExpression>(arguments[0]);
	if (sequence)
	{
		int elements = sequence->noArguments;
		for (int c = 0; c < elements; c++)
		{
			a->set(c, sequence->arguments[c]->getResult());
		}
	}
	else
	{
		int elements = (int)*arguments[0]->evaluate().get<Real>();
		for (int c = 0; c < elements; c++)
		{
			a->set(c, Variable());
		}
	}
	return var;
}
