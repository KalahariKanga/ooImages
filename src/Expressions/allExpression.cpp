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
	Variable var(new Mask(i->getWidth(), i->getHeight()));
	auto mask = var.get<Mask>();
	for (int cx = 0; cx < mask->width; cx++)
		for (int cy = 0; cy < mask->height; cy++)
			mask->setValue(cx, cy, 1);
	return var;
}

