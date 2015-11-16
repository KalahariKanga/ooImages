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

	setLocalVariable("r", &r);
	setLocalVariable("g", &g);
	setLocalVariable("b", &b);
	setLocalVariable("h", &h);
	setLocalVariable("s", &s);
	setLocalVariable("v", &v);
	setLocalVariable("x", &x);
	setLocalVariable("y", &y);

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
