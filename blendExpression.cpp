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
	Variable topVar = arguments[0]->getResult();
	ImageObject* top = topVar.get<ImageObject>();

	setLocalVariable("x",Variable(x));
	setLocalVariable("y",Variable(y));
	setLocalVariable("r1",Variable(r1));
	setLocalVariable("g1",Variable(g1));
	setLocalVariable("b1",Variable(b1));
	setLocalVariable("h1",Variable(h1));
	setLocalVariable("s1",Variable(s1));
	setLocalVariable("v1",Variable(v1));
	setLocalVariable("r2",Variable(r2));
	setLocalVariable("g2",Variable(g2));
	setLocalVariable("b2",Variable(b2));
	setLocalVariable("h2",Variable(h2));
	setLocalVariable("s2",Variable(s2));
	setLocalVariable("v2",Variable(v2));

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
				Variable col = arguments[1]->getResult();
				buffer->setPixel(cx, cy, *col.get<Colour>());
			}

		}
	commitBuffer();
	return Variable(Variable::Type::Void);
}

