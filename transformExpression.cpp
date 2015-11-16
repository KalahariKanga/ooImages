#include "transformExpression.h"


transformExpression::transformExpression()
{
	noArguments = 2;
	setLocalVariable("r", &r);
	setLocalVariable("g", &g);
	setLocalVariable("b", &b);
	setLocalVariable("h", &h);
	setLocalVariable("s", &s);
	setLocalVariable("v", &v);
	setLocalVariable("x", &x);
	setLocalVariable("y", &y);
}


transformExpression::~transformExpression()
{
	
}

Variable transformExpression::evaluate()
{
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
			float nx = *arguments[0]->getResult().get<float>();
			float ny = *arguments[1]->getResult().get<float>();
			buffer->setPixel(cx, cy, image->getPixel(nx, ny));
		}
	commitBuffer();
	return Variable(Variable::Type::Void);
}
