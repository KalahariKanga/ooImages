#pragma once
#include "stdafx.h"

#include "AbstractMask.h"
#include "Mask.h"

using namespace std;

class Selection : public AbstractMask
{
	bool** data;
	bool isInCircle(int x, int y, int cx, int cy, int cr);
	bool isInRectangle(int x, int y, int x1, int y1, int x2, int y2);
	bool isInEllipse(int x, int y, int x1, int y1, int x2, int y2);
	bool isInRegion(ImageObject *i, int x, int y, std::string expr);

public:
	Selection(int width, int height);
	Selection(vector<string> tokens, ImageObject* image);
	Selection(Mask& mask, float boundary);
	~Selection();
	virtual float getValue(int x, int y);
	void setValue(int x, int y, bool v);
	void toCircle(string cx, string cy, string cr);
	void toRectangle(string x1, string y1, string x2, string y2);
	void toEllipse(string x1, string y1, string x2, string y2);
	void toRegion(ImageObject *i, std::string expr);

	void toRectangle(int x1, int y1, int x2, int y2);
	virtual void invert();

	
	virtual void combine(string op, AbstractMask* other);
	void dilate(Selection* kernel);
	void erode(Selection* kernel);
	static Selection create(vector<string> tokens, ImageObject* image);
	static Selection create(vector<string> tokens, int width, int height);
	//TODO:make this a constructor you damned silly

	static Selection createStructuringElement(vector<string>);
};


