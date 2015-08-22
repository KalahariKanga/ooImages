#include "Transform.h"


Transform::Transform()
{
}
Transform::Transform(ImageObject* image, AbstractMask* mask)
	:ImageModifier(image, mask)
{

}

Transform::~Transform()
{
}

void Transform::apply()
{
	float x, y, r, g, b, h, s, v;
	ExpressionParser parser[2];
	for (int c = 0; c < 2; c++)
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
			if (mask->getValue(x, y))
			{
				Colour p = image->getPixel((int)x, (int)y);
				r = p.r();
				g = p.g();
				b = p.b();
				h = p.h();
				s = p.s();
				v = p.v();
				double nx = parser[0].evaluate();
				double ny = parser[1].evaluate();
				buffer->setPixel(x, y, image->getPixel((float)nx,(float)ny));
			}
			else
				buffer->setPixel(x, y, image->getPixel((int)x, (int)y));
		}
}