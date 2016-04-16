#include "flattenExpression.h"


flattenExpression::flattenExpression()
{
	noArguments = 0;
}


flattenExpression::~flattenExpression()
{
}

Variable flattenExpression::evaluate()
{
	for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
		{
			auto c = image->getPixel(cx, cy);
			c.r(c.r()*(float)c.a() / 255);
			c.g(c.g()*(float)c.a() / 255);
			c.b(c.b()*(float)c.a() / 255);
			c.a(255);
			buffer->setPixel(cx, cy, c);
		}
	commitBuffer();
	return Variable();
}
