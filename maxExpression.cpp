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
	float x, y, r, g, b, h, s, v;
	addLocalVariable("x", &x);
	addLocalVariable("y", &y);
	addLocalVariable("h", &h);
	addLocalVariable("s", &s);
	addLocalVariable("v", &v);
	addLocalVariable("r", &r);
	addLocalVariable("g", &g);
	addLocalVariable("b", &b);

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
				if (*var.get<float>() > max)
					max = *var.get<float>();
			}
		}
	Variable var(Variable::Type::Real);
	var.set<float>(new float(max));
	return var;
}