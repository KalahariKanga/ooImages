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

	setLocalVariable("r", Variable(r));
	setLocalVariable("g", Variable(g));
	setLocalVariable("b", Variable(b));
	setLocalVariable("h", Variable(h));
	setLocalVariable("s", Variable(s));
	setLocalVariable("v", Variable(v));
	setLocalVariable("x", Variable(x));
	setLocalVariable("y", Variable(y));

	for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
		{
			if (store->mask->getValue(cx, cy) > 0)
			{
				Colour p = image->getPixel(cx, cy);
				x = cx;
				y = cy;
				r = p.r();
				g = p.g();
				b = p.b();
				h = p.h();
				s = p.s();
				v = p.v();
				Variable col = arguments.back()->getResult();
				buffer->setPixel(cx, cy, *col.get<Colour>());
			}
		}
	commitBuffer();
	return Variable(Variable::Type::Void);
}
