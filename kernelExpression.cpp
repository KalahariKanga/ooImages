#include "kernelExpression.h"
#include "SequenceExpression.h"

kernelExpression::kernelExpression()
{
	noArguments = 1;
}


kernelExpression::~kernelExpression()
{
}

Variable kernelExpression::evaluate()
{
	auto sequence = std::dynamic_pointer_cast<SequenceExpression>(arguments[0]);

	if (!sequence)
		throw new Exception(Exception::ErrorType::MISMATCHED_BRACKETS);//kinda

	int elements = sequence->noArguments;
	int size = (int)ceil(sqrt((float)elements));
	Variable var(new Kernel(size));
	auto k = var.get<Kernel>();

	for (int c = 0; c < size*size; c++)
	{
		if (c < elements)
		{
			k->set(c%size, c / size, *sequence->arguments[c]->getResult().get<Real>());
		}
		else
			k->set(c%size, c / size, 0);
	}
	return var;
}