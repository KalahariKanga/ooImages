#pragma once
#include <SFML/Graphics.hpp>
#include "core.h"
class Colour
{
	sf::Color col;
	int R, G, B, H, S, V;
public:
	int r(), g(), b(), h(), s(), v();
	void r(int), g(int), b(int), h(int), s(int), v(int);
	void hsv(int, int, int);
	sf::Color getCol();
	Colour(void);
	Colour(int r, int g, int b);
	~Colour(void);
};

