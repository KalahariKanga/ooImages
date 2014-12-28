#include "HsvTransform.h"


HsvTransform::HsvTransform()
{
}
HsvTransform::HsvTransform(ImageObject* image, Mask* mask)
	:PixelModifier(image, mask)
{
}

HsvTransform::~HsvTransform()
{
}

void HsvTransform::setup()
{
	for (int c = 0; c < 3; c++)
	{
		parser[c].setString(expr[c]);
		parser[c].addLocalVariable("x", &x);
		parser[c].addLocalVariable("y", &y);
		parser[c].addLocalVariable("r", &r);
		parser[c].addLocalVariable("g", &g);
		parser[c].addLocalVariable("b", &b);
		parser[c].addLocalVariable("h", &h);
		parser[c].addLocalVariable("s", &s);
		parser[c].addLocalVariable("v", &v);
	}
}

Colour HsvTransform::modifyPixel(int x, int y)
{
	this->x = x;
	this->y = y;
	Colour p = image->getPixel(x, y);
	r = p.r();
	g = p.g();
	b = p.b();
	h = p.h();
	s = p.s();
	v = p.v();
	p.hsv(parser[0].evaluate(), parser[1].evaluate(), parser[2].evaluate());
	return p;	
}