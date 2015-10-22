#include "blendExpression.h"


blendExpression::blendExpression()
{
	noArguments = 2;
}


blendExpression::~blendExpression()
{
}

Variable blendExpression::evaluate()
{
	ImageStore* store = ImageStore::get();
	ImageObject* bottom = store->getImage();
	Variable topVar = arguments[0]->evaluate();
	ImageObject* top = topVar.get<ImageObject>();
	float x, y;
	float r1, g1, b1, h1, s1, v1;
	float r2, g2, b2, h2, s2, v2;
	addLocalVariable("x", &x);
	addLocalVariable("y", &y);

	addLocalVariable("h1", &h1);
	addLocalVariable("s1", &s1);
	addLocalVariable("v1", &v1);
	addLocalVariable("r1", &r1);
	addLocalVariable("g1", &g1);
	addLocalVariable("b1", &b1);
	
	addLocalVariable("h2", &h2);
	addLocalVariable("s2", &s2);
	addLocalVariable("v2", &v2);
	addLocalVariable("r2", &r2);
	addLocalVariable("g2", &g2);
	addLocalVariable("b2", &b2);

	for (int cx = 0; cx < std::min(top->getWidth(),bottom->getWidth()); cx++)
		for (int cy = 0; cy < std::min(top->getHeight(), bottom->getHeight()); cy++)
		{
			x = cx;
			y = cy;
			if (store->mask->getValue(cx, cy) > 0)
			{
				Colour b = bottom->getPixel(cx, cy);
				r1 = b.r();
				g1 = b.g();
				b1 = b.b();
				h1 = b.h();
				s1 = b.s();
				v1 = b.v();
				Colour t = top->getPixel(cx, cy);
				r2 = t.r();
				g2 = t.g();
				b2 = t.b();
				h2 = t.h();
				s2 = t.s();
				v2 = t.v();
				Variable col = arguments[1]->evaluate();
				buffer->setPixel(cx, cy, *col.get<Colour>());
			}

		}
	commitBuffer();
	return Variable(Variable::Type::Void);
}
