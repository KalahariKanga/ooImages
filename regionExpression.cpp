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
	ImageObject* image = store->image;
	Selection* sel = new Selection(image->getWidth(), image->getHeight());

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
				float v = arguments.back()->evaluate().real;
				if (v > 0)
					sel->setValue(cx, cy, true);
				else
					sel->setValue(cx, cy, false);
			}
		}
	Variable var(Variable::Type::Selection);
	var.selection = sel;
	return var;
}
