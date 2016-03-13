#include "regionExpression.h"


regionExpression::regionExpression()
{
	noArguments = 1;
}

regionExpression::~regionExpression()
{
}

Variable regionExpression::evaluate()
{
	ImageObject* image = store->getImage();
	Variable var(new Mask(image->getWidth(), image->getHeight()));
	auto mask = var.get<Mask>();

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
				Colour p = image->getPixel(cx, cy);
				x = cx;
				y = cy;
				r = p.r();
				g = p.g();
				b = p.b();
				h = p.h();
				s = p.s();
				v = p.v();

				float val = *arguments.back()->getResult().get<Real>();
				mask->setValue(cx, cy, val);
		}
	return var;
}
