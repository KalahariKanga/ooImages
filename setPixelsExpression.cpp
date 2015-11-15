#include "setPixelsExpression.h"


setPixelsExpression::setPixelsExpression()
{
	noArguments = 1;
}


setPixelsExpression::~setPixelsExpression()
{
}

Variable setPixelsExpression::evaluate()
{
	ImageStore* store = ImageStore::get();
	ImageObject* image = store->getImage();
	
	for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
		{
			if (store->mask->getValue(cx, cy) > 0)
			{
				Colour p = image->getPixel(cx, cy);
				setLocalVariable("x", cx);
				setLocalVariable("y", cy);
				setLocalVariable("h", p.h());
				setLocalVariable("s", p.s());
				setLocalVariable("v", p.v());
				setLocalVariable("r", p.r());
				setLocalVariable("g", p.g());
				setLocalVariable("b", p.b());
				Variable col = arguments.back()->getResult();
				buffer->setPixel(cx, cy, *col.get<Colour>());
			}
		}
	commitBuffer();
	return Variable(Variable::Type::Void);
}