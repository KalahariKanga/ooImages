#include "minExpression.h"


minExpression::minExpression()
{
	noArguments = 1;
}


minExpression::~minExpression()
{
}

Variable minExpression::evaluate()
{
	ImageObject* image = store->getImage();	

	setLocalVariable("r", &r);
	setLocalVariable("g", &g);
	setLocalVariable("b", &b);
	setLocalVariable("h", &h);
	setLocalVariable("s", &s);
	setLocalVariable("v", &v);
	setLocalVariable("x", &x);
	setLocalVariable("y", &y);

	float min = std::numeric_limits<float>::max();

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
				Variable var = arguments.back()->getResult();
				if (*var.get<Real>() < min)
					min = *var.get<Real>();
			}
		}
	return Variable(min);
}