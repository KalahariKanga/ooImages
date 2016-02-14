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
	Variable var(Variable::Type::Kernel);

	auto sequence = dynamic_pointer_cast<SequenceExpression>(arguments[0]);

	if (!sequence)
		throw new Exception(Exception::ErrorType::MISMATCHED_BRACKETS);//kinda

	int elements = sequence->noArguments;
	int size = (int)ceil(sqrt((float)elements));
	Kernel* k = new Kernel(size);

	for (int c = 0; c < size*size; c++)
	{
		if (c < elements)
		{
			k->set(c%size, c / size, *sequence->arguments[c]->getResult().get<Real>());
		}
		else
			k->set(c%size, c / size, 0);
	}

	var.set(k);
	return var;
}