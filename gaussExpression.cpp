#include "gaussExpression.h"


gaussExpression::gaussExpression()
{
	noArguments = 2;
}


gaussExpression::~gaussExpression()
{
}

Variable gaussExpression::evaluate()
{
	int size = *arguments[0]->getResult().get<Real>();
	float sigma = *arguments[1]->getResult().get<Real>();
	Variable var(new Kernel(size));
	auto k = var.get<Kernel>();
	int origin = size / 2;
	for (int cx = 0; cx < size; cx++)
		for (int cy = 0; cy < size; cy++)
		{
			float v = exp(- ( (cx - origin)*(cx - origin) / (2 * sigma * sigma) + (cy - origin)*(cy - origin) / (2 * sigma * sigma) ));
			k->set(cx, cy, v);
		}
	return var;
}
