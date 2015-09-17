#include "kernelExpression.h"


kernelExpression::kernelExpression()
{
	noArguments = 9;
}


kernelExpression::~kernelExpression()
{
}

Variable kernelExpression::evaluate()
{
	Variable var(Variable::Type::Kernel);
	Kernel* k = new Kernel(3);
	for (int c = 0; c < 9; c++)
	{
		k->set(c / 3, c % 3, arguments[c]->evaluate().real);
	}
	var.kernel = k;
	return var;
}