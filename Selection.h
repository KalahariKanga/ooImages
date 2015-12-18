#pragma once
#include "stdafx.h"

#include "AbstractMask.h"
#include "Mask.h"

using namespace std;

class Selection : public AbstractMask
{
	bool** data;

public:
	Selection(int width, int height);
	Selection(Mask& mask, float boundary);
	Selection(const Selection& obj);
	~Selection();
	virtual float getValue(int x, int y);
	void setValue(int x, int y, bool v);
	
	virtual void invert();

	void dilate(Selection* kernel);
	void erode(Selection* kernel);

	static void loadProperties();
};


