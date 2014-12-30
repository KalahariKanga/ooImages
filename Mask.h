#pragma once
#include "stdafx.h"
#include "ExpressionParser.h"
#include "ImageObject.h"
#include "Colour.h"
using namespace std;
class Mask
{
	float** data;
	float valueInCircle(int x, int y, int cx, int cy, int r1, int r2);
	float valueInLine(int x, int y, int x1, int y1, int x2, int y2);
	float valueInRegion(ImageObject* i, int x, int y, std::string expr);
protected:
	int width, height;
public:
	virtual float getValue(int x, int y);
	virtual void setValue(int x, int y, float v);
	void toCircle(string cx, string cy, string r1, string r2);
	void toLine(string x1, string y1, string x2, string y2);
	void toRegion(ImageObject* i, std::string expr);
	void combine(std::string op, Mask* other);
	void invert();
	Mask();
	Mask(int width, int height);
	Mask(vector<std::string> tokens, ImageObject* image);
	~Mask();
};

