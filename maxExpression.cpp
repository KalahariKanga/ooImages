#include "maxExpression.h"

maxExpression::maxExpression()
{
	noArguments = 1;
}


maxExpression::~maxExpression()
{
}

Variable maxExpression::evaluate()
{
	ImageStore* store = ImageStore::get();
	ImageObject* image = store->getImage();
	
	setLocalVariable("r",Variable(r));
	setLocalVariable("g",Variable(g));
	setLocalVariable("b",Variable(b));
	setLocalVariable("h",Variable(h));
	setLocalVariable("s",Variable(s));
	setLocalVariable("v",Variable(v));
	setLocalVariable("x",Variable(x));
	setLocalVariable("y",Variable(y));

	float max = std::numeric_limits<float>::min();

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
				if (*var.get<Real>() > max)
					max = *var.get<Real>();
			}
		}
	
	return Variable(max);
}