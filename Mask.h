#pragma once
#include "stdafx.h"
#include "AbstractMask.h"


using namespace std;
class Mask : public AbstractMask
{
	float** data;

public:
	virtual float getValue(int x, int y);
	void setValue(int x, int y, float v);
	virtual void invert();
	Mask(int width, int height);
	~Mask();
};

