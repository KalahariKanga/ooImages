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
			Colour p = image->getPixel(cx, cy);
			x = cx;
			y = cy;
			r = p.r();
			g = p.g();
			b = p.b();
			h = p.h();
			s = p.s();
			v = p.v();
			float nx = arguments[0]->evaluate().real;
			float ny = arguments[1]->evaluate().real;
			buffer->setPixel(cx, cy, image->getPixel(nx, ny));
		}
	commitBuffer();
	return Variable(Variable::Type::Void);
}
