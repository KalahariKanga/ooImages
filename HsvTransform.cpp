#include "HsvTransform.h"


HsvTransform::HsvTransform()
{
}
HsvTransform::HsvTransform(ImageObject* image, Selection* selection)
	:ImageModifier(image, selection)
{
}

HsvTransform::~HsvTransform()
{
}

void HsvTransform::apply()
{
	double x, y, r, g, b, h, s, v;
	ExpressionParser parser[3];
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
	for (x = 0; x < image->getWidth(); x += 1)
		for (y = 0; y < image->getHeight(); y += 1)
		{
			if (selection->getValue(x, y))
			{
				Colour p = image->getPixel((int)x, (int)y);
				r = p.r();
				g = p.g();
				b = p.b();
				h = p.h();
				s = p.s();
				v = p.v();
				p.hsv(parser[0].evaluate(), parser[1].evaluate(), parser[2].evaluate());
				buffer->setPixel(x, y, p);
			}
			else
				buffer->setPixel(x, y, image->getPixel((int)x, (int)y));
		}
}