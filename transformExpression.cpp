#include "transformExpression.h"


transformExpression::transformExpression()
{
	noArguments = 2;
}


transformExpression::~transformExpression()
{
	
}

Variable transformExpression::evaluate()
{
	setLocalVariable("r", Variable(r));
	setLocalVariable("g", Variable(g));
	setLocalVariable("b", Variable(b));
	setLocalVariable("h", Variable(h));
	setLocalVariable("s", Variable(s));
	setLocalVariable("v", Variable(v));
	setLocalVariable("x", Variable(x));
	setLocalVariable("y", Variable(y));

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
			float nx = *arguments[0]->getResult().get<Real>();
			float ny = *arguments[1]->getResult().get<Real>();
			buffer->setPixel(cx, cy, image->getPixel(nx, ny));
		}
	commitBuffer();
	return Variable(Variable::Type::Void);
}
