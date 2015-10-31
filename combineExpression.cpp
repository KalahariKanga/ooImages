#include "combineExpression.h"


combineExpression::combineExpression()
{
	noArguments = 3;
}


combineExpression::~combineExpression()
{
}

Variable combineExpression::evaluate()
{
	Variable result(Variable::Type::Mask);
	Variable mv1 = arguments[0]->evaluate();
	AbstractMask* m1 = mv1.get<Mask>();
	Variable mv2 = arguments[1]->evaluate();
	AbstractMask* m2 = mv2.get<Mask>();
	Mask* mask = new Mask(std::min(m1->width, m2->width), std::min(m1->height, m2->height));
	float v1, v2;
	addLocalVariable("v1", &v1);
	addLocalVariable("v2", &v2);

	for (int cx = 0; cx < mask->width; cx++)
		for (int cy = 0; cy < mask->height; cy++)
		{
			v1 = m1->getValue(cx, cy);
			v2 = m2->getValue(cx, cy);
			mask->setValue(cx, cy, *arguments[2]->evaluate().get<float>());
		}
	result.set<Mask>(mask);
	return result;
}
