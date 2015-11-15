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

	for (int cx = 0; cx < std::min(top->getWidth(),bottom->getWidth()); cx++)
		for (int cy = 0; cy < std::min(top->getHeight(), bottom->getHeight()); cy++)
		{
			setLocalVariable("x", cx);
			setLocalVariable("y", cy);
			if (store->mask->getValue(cx, cy) > 0)
			{
				Colour b = bottom->getPixel(cx, cy);
				setLocalVariable("r1", b.r() );
				setLocalVariable("g1", b.g() );
				setLocalVariable("b1", b.b() );
				setLocalVariable("h1", b.h() );
				setLocalVariable("s1", b.s() );
				setLocalVariable("v1", b.v() );
				Colour t = top->getPixel(cx, cy);
				setLocalVariable("r2", t.r());
				setLocalVariable("g2", t.g());
				setLocalVariable("b2", t.b());
				setLocalVariable("h2", t.h());
				setLocalVariable("s2", t.s());
				setLocalVariable("v2", t.v());
				Variable col = arguments[1]->getResult();
				buffer->setPixel(cx, cy, *col.get<Colour>());
			}

		}
	commitBuffer();
	return Variable(Variable::Type::Void);
}

