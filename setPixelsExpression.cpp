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
	ImageObject* image = store->image;
	float x, y, r, g, b, h, s, v;
	addLocalVariable("x", &x);
	addLocalVariable("y", &y);
	addLocalVariable("h", &h);
	addLocalVariable("s", &s);
	addLocalVariable("v", &v);
	addLocalVariable("r", &r);
	addLocalVariable("g", &g);
	addLocalVariable("b", &b);

	for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
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
			image->setPixel(cx, cy, *arguments.back()->evaluate().colour);
		}
	return Variable(Variable::Type::Void);
}