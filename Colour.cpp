#include "Colour.h"

RESOURCE_DEFINE_STATIC_PROPERTY_MAP(Colour)

Colour::Colour(void) : Colour(0,0,0,255)
{
}
Colour::Colour(int R, int G, int B, int A) : R(R), G(G), B(B), A(A)
{
}

Colour::~Colour(void)
{
}

int Colour::r()
{
	return R;
}
int Colour::g()
{
	return G;
}
int Colour::b()
{
	return B;
}
int Colour::a()
{
	return A;
}
int Colour::h()
{
	float min, max, delta, h;
	min = std::min(R, std::min(G, B));
	max = std::max(R, std::max(G, B));
	delta = max - min;

	if (R == max)
		h = (G - B) / delta;
	else if (G == max)
		h = 2 + (B - R) / delta;
	else
		h = 4 + (R - G) / delta;
	h *= ((float)256 / 6);
	if (h < 0)
		h += 256;
	return h;
}
int Colour::s()
{
	float min, max, delta;
	min = std::min(R, std::min(G, B));
	max = std::max(R, std::max(G, B));
	delta = max - min;
	if (max != 0)
		return 255*(delta / max);
	else
		return 0;
}
int Colour::v()
{
	return std::max(R, std::max(G, B));
}

void Colour::r(int r)
{
	R = r;
}
void Colour::g(int g)
{
	G = g;
}
void Colour::b(int b)
{
	B = b;
}
void Colour::a(int a)
{
	A = a;
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

	R = r * 255;
	G = g * 255;
	B = b * 255;
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
	std::cout << "Colour\n";
	std::cout << "R: " << r() << " G: " << g() << " B: " << b() << "\n";

}

void Colour::loadProperties()
{
	setProperty("r", [](Colour* c){return c->r(); });
	setProperty("g", [](Colour* c){return c->g(); });
	setProperty("b", [](Colour* c){return c->b(); });
	setProperty("h", [](Colour* c){return c->h(); });
	setProperty("s", [](Colour* c){return c->s(); });
	setProperty("v", [](Colour* c){return c->v(); });
}