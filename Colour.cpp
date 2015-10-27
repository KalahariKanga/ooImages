#include "Colour.h"


Colour::Colour(void)
{
	setProperty("r", [this](){return r(); });
	setProperty("g", [this](){return g(); });
	setProperty("b", [this](){return b(); });
	setProperty("h", [this](){return h(); });
	setProperty("s", [this](){return s(); });
	setProperty("v", [this](){return v(); });
}
Colour::Colour(int r, int g, int b, int a)
{
	col.r = r;
	col.g = g;
	col.b = b;
	col.a = a;
}

Colour::~Colour(void)
{
}

int Colour::r()
{
	return col.r;
}
int Colour::g()
{
	return col.g;
}
int Colour::b()
{
	return col.b;
}
int Colour::a()
{
	return col.a;
}
int Colour::h()
{
	float min, max, delta, h;
	min = std::min(col.r, std::min(col.g, col.b));
	max = std::max(col.r, std::max(col.g, col.b));
	delta = max - min;

	if (col.r == max)
		h = (col.g - col.b) / delta;
	else if (col.g == max)
		h = 2 + (col.b - col.r) / delta;
	else
		h = 4 + (col.r - col.g) / delta;
	h *= ((float)256 / 6);
	if (h < 0)
		h += 256;
	return h;
}
int Colour::s()
{
	float min, max, delta;
	min = std::min(col.r, std::min(col.g, col.b));
	max = std::max(col.r, std::max(col.g, col.b));
	delta = max - min;
	if (max != 0)
		return 255*(delta / max);
	else
		return 0;
}
int Colour::v()
{
	return std::max(col.r, std::max(col.g, col.b));
}

sf::Color Colour::getCol()
{
	return col;
}

void Colour::r(int r)
{
	col.r = r;
}
void Colour::g(int g)
{
	col.g = g;
}
void Colour::b(int b)
{
	col.b = b;
}
void Colour::a(int a)
{
	col.a = a;
}
void Colour::h(int h)
{
	hsv(h, s(), v());
}
void Colour::s(int s)
{
	hsv(h(), s, v());
}
void Colour::v(int v)
{
	hsv(h(), s(), v);
}
void Colour::hsv(int H, int S, int V)
{
	float r, g, b;
	float h = (float)H / 255;
	float s = (float)S / 255;
	float v = (float)V / 255;

	int i = floor((float)h * 6);
	float f = h * 6 - i;
	float p = v * (1 - s);
	float q = v * (1 - f * s);
	float t = v * (1 - (1 - f) * s);

	switch (i % 6){
	case 0: r = v, g = t, b = p; break;
	case 1: r = q, g = v, b = p; break;
	case 2: r = p, g = v, b = t; break;
	case 3: r = p, g = q, b = v; break;
	case 4: r = t, g = p, b = v; break;
	case 5: r = v, g = p, b = q; break;
	}

	col.r = r * 255;
	col.g = g * 255;
	col.b = b * 255;
}

Colour Colour::interpolate(Colour from, Colour to, float amount)
{
	if (amount <= 0)
		return from;
	if (amount >= 1)
		return to;
	Colour newColour;
	newColour.r(from.r() + amount*(to.r() - from.r()));
	newColour.g(from.g() + amount*(to.g() - from.g()));
	newColour.b(from.b() + amount*(to.b() - from.b()));
	newColour.a(from.a() + amount*(to.a() - from.a()));
	return newColour;
}

float Colour::distance(Colour from, Colour to)
{
	///using 2-norm, could use 1-norm for speed

	int dR = (from.r() - to.r());
	dR *= dR;
	int dG = (from.g() - to.g());
	dG *= dG;
	int dB = (from.b() - to.b());
	dB *= dB;
	return sqrt(dR + dG + dB);
}

void Colour::about()
{
	std::cout << "About\n";
	std::cout << "R: " << r() << " G: " << g() << " B: " << b() << "\n";

}