#pragma once
#include "stdafx.h"

#include "Mask.h"

using namespace std;

class Selection : public Mask
{
	bool** data;
	int width, height;
	bool isInCircle(int x, int y, int cx, int cy, int cr);
	bool isInRectangle(int x, int y, int x1, int y1, int x2, int y2);
	bool isInEllipse(int x, int y, int x1, int y1, int x2, int y2);
	bool isInRegion(ImageObject *i, int x, int y, std::string expr);

public:
	Selection(int width, int height);
	Selection(vector<string> tokens, ImageObject* image);
	~Selection();
	bool getValue(int x, int y);
	void setValue(int x, int y, bool v);
	void toCircle(string cx, string cy, string cr);
	void toRectangle(string x1, string y1, string x2, string y2);
	void toEllipse(string x1, string y1, string x2, string y2);
	void toRegion(ImageObject *i, std::string expr);
	void invert();

	Selection combine(string op, Selection* other);
	Selection dilate(Selection* kernel, int originx, int originy);
	Selection erode(Selection* kernel, int originx, int originy);
	Selection dilate(Selection* kernel);//assume centre origin
	Selection erode(Selection* kernel);
	static Selection create(vector<string> tokens, ImageObject* image);
	static Selection create(vector<string> tokens, int width, int height);
	//TODO:make this a constructor you damned silly

	static Selection createStructuringElement(vector<string>);
};


