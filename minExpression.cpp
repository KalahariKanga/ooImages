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
	Variable var(Variable::Type::Real);
	var.set<float>(new float(min));
	return var;
}