#include "transformExpression.h"


transformExpression::transformExpression()
{
	noArguments = 2;
}


transformExpression::~transformExpression()
{
	
}

Variable transformExpression::evaluate()
{
	ImageStore* store = ImageStore::get();
	setLocalVariable("r", &r);
	setLocalVariable("g", &g);
	setLocalVariable("b", &b);
	setLocalVariable("h", &h);
	setLocalVariable("s", &s);
	setLocalVariable("v", &v);
	setLocalVariable("a", &a);
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
				a = p.a();
				float nx = *arguments[0]->getResult().get<Real>();
				float ny = *arguments[1]->getResult().get<Real>();
				buffer->setPixel(cx, cy, image->getPixel(nx, ny));
			}
		}
	commitBuffer();
	return Variable();
}
