#pragma once
#include <cmath>
#include <memory>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#define PI 3.14159265
template <typename T> T clamp(const T& value, const T& low, const T& high)
{
	return value < low ? low : (value > high ? high : value);
}

float bilint(float topLeft, float topRight, float bottomLeft, float bottomRight, float x, float y);

bool and(bool a, bool b);
bool or(bool a, bool b);
bool nand(bool a, bool b);
bool xor(bool a, bool b);
bool not(bool a);

float distance(int x1, int y1, int x2, int y2);