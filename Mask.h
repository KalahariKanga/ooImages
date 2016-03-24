#pragma once
#include "stdafx.h"
#include "ResourcePropertyHelper.h"

class Mask : public ResourcePropertyHelper<Mask>
{
	float** data;

public:
	Mask(int width, int height);
	Mask(const Mask& obj);
	~Mask();
	int width, height;
	float getValue(int x, int y);
	void setValue(int x, int y, float v);
	void resize(int w, int h);
	void invert();
	void about();
	static void loadProperties();
};

