#pragma once
#include <cmath>
#include <memory>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <fstream>

#define PI 3.14159265
template <typename T> T clamp(const T& value, const T& low, const T& high)
{
	return value < low ? low : (value > high ? high : value);
}

float bilint(float topLeft, float topRight, float bottomLeft, float bottomRight, float x, float y);
