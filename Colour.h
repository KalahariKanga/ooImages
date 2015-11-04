#pragma once
#include <SFML/Graphics.hpp>
#include "core.h"
#include "Resource.h"

class Colour : public Resource
{
	int R, G, B, A;
public:
	int r(), g(), b(), h(), s(), v(), a();
	void r(int), g(int), b(int), h(int), s(int), v(int), a(int);
	void hsv(int, int, int);
	
	Colour(void);
	Colour(int r, int g, int b, int a = 255);
	
	~Colour(void);
	static Colour interpolate(Colour from, Colour to, float amount);
	static float distance(Colour from, Colour to);
	virtual void about();
};


