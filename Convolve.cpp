#include "Convolve.h"


Convolve::Convolve()
{
}
Convolve::Convolve(ImageObject* image, Selection* selection)
	:ImageModifier(image, selection)
{

}

Convolve::~Convolve()
{
}

void Convolve::apply()
{
	ExpressionParser parser[3][3];
	Colour source[3][3];
	double x, y, r, g, b, h, s, v;
	for (int c = 0; c < 9; c++)
	{
		parser[c / 3][c % 3].setString(expr[c]);
		parser[c / 3][c % 3].addLocalVariable("x", &x);
		parser[c / 3][c % 3].addLocalVariable("y", &y);
		parser[c / 3][c % 3].addLocalVariable("r", &r);
		parser[c / 3][c % 3].addLocalVariable("g", &g);
		parser[c / 3][c % 3].addLocalVariable("b", &b);
		parser[c / 3][c % 3].addLocalVariable("h", &h);
		parser[c / 3][c % 3].addLocalVariable("s", &s);
		parser[c / 3][c % 3].addLocalVariable("v", &v);

	}

	for (x = 0; x < image->getWidth(); x += 1)
		for (y = 0; y < image->getHeight(); y += 1)
		{
			if (selection->getValue((int)x, (int)y))
			{
				Colour p;
				p = image->getPixel((int)x, (int)y);
				r = p.r();
				g = p.g();
				b = p.b();
				h = p.h();
				s = p.s();
				v = p.v();
				int r = 0, g = 0, b = 0;
				for (int cx = -1; cx <= 1; cx++)
					for (int cy = -1; cy <= 1; cy++)
					{
						p = image->getPixel((int)x + cx, (int)y + cy);
						r += parser[1 + cx][1 + cy].evaluate()*p.r();
						g += parser[1 + cx][1 + cy].evaluate()*p.g();
						b += parser[1 + cx][1 + cy].evaluate()*p.b();
					}
				r = clamp(r, 0, 255);
				g = clamp(g, 0, 255);
				b = clamp(b, 0, 255);
				buffer->setPixel(x, y, Colour(r, g, b));
			}
			else
				buffer->setPixel(x, y, image->getPixel((int)x, (int)y));
		}
}
