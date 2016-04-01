#include "Colour.h"

RESOURCE_DEFINE_STATIC_PROPERTY_MAP(Colour)

Colour::Colour(void) : Colour(0,0,0,255)
{
}
Colour::Colour(int r, int g, int b, int a)
{
	R = clamp<int>(r, 0, 255);
	G = clamp<int>(g, 0, 255);
	B = clamp<int>(b, 0, 255);
	A = clamp<int>(a, 0, 255);
}

Colour::Colour(const Colour& obj)
{
	R = obj.R;
	G = obj.G;
	B = obj.B;
	A = obj.A;
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
	int min, max, delta;
	float h;
	min = std::min(R, std::min(G, B));
	max = std::max(R, std::max(G, B));
	delta = max - min;

	if (R == max)
		h = (G - B) / (float)delta;
	else if (G == max)
		h = 2 + (B - R) / (float)delta;
	else
		h = 4 + (R - G) / (float)delta;

	h *= ((float)256 / 6);

	if (h < 0)
		h += 256;

	return (int)h;
}
int Colour::s()
{
	int min, max, delta;
	min = std::min(R, std::min(G, B));
	max = std::max(R, std::max(G, B));
	delta = max - min;
	if (max != 0)
		return (int)(255*(delta / (float)max));
	else
		return 0;
}
int Colour::v()
{
	return std::max(R, std::max(G, B));
}

void Colour::r(int r)
{
	R = clamp<int>(r, 0, 255);
}
void Colour::g(int g)
{
	G = clamp<int>(g, 0, 255);
}
void Colour::b(int b)
{
	B = clamp<int>(b, 0, 255);
}
void Colour::a(int a)
{
	A = clamp<int>(a, 0, 255);
}
void Colour::h(int h)
{
	h = h % 255;
	hsv(h, s(), v());
}
void Colour::s(int s)
{
	s = clamp<int>(s, 0, 255);
	hsv(h(), s, v());
}
void Colour::v(int v)
{
	v = clamp<int>(v, 0, 255);
	hsv(h(), s(), v);
}
void Colour::hsv(int H, int S, int V)
{
	float r = 0, g = 0, b = 0;
	H = H % 255;
	S = clamp<int>(S, 0, 255);
	V = clamp<int>(V, 0, 255);
	float h = (float)H / 255;
	float s = (float)S / 255;
	float v = (float)V / 255;

	int i = (int)floor(h * 6);
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

	R = (int)(r * 255);
	G = (int)(g * 255);
	B = (int)(b * 255);
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
	return (float)sqrt(dR + dG + dB);
}

void Colour::about()
{
	std::cout << "About\n";
	std::cout << "Colour\n";
	std::cout << "R: " << r() << " G: " << g() << " B: " << b() << "\n";

}

void Colour::loadProperties()
{
	setProperty("r", [](Colour* c){return (float)c->r(); });
	setProperty("g", [](Colour* c){return (float)c->g(); });
	setProperty("b", [](Colour* c){return (float)c->b(); });
	setProperty("h", [](Colour* c){return (float)c->h(); });
	setProperty("s", [](Colour* c){return (float)c->s(); });
	setProperty("v", [](Colour* c){return (float)c->v(); });
	setProperty("a", [](Colour* c){return (float)c->a(); });
}