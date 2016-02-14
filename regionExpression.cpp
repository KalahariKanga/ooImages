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
	ImageStore* store = ImageStore::get();
	ImageObject* image = store->getImage();
	Mask* mask = new Mask(image->getWidth(), image->getHeight());
	
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
	Variable var(Variable::Type::Mask);
	var.set(mask);
	return var;
}
