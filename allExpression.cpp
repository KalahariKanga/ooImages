#include "allExpression.h"


allExpression::allExpression()
{
	noArguments = 0;
}


allExpression::~allExpression()
{
}

Variable allExpression::evaluate()
{
	ImageObject* i = ImageStore::get()->getImage();
	Mask* mask = new Mask(i->getWidth(), i->getHeight());
	for (int cx = 0; cx < mask->width; cx++)
		for (int cy = 0; cy < mask->height; cy++)
			mask->setValue(cx, cy, 1);
	Variable var(Variable::Type::Mask);
	var.set<Mask>(mask);
	return var;
}

