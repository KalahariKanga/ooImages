#pragma once
#include "stdafx.h"
#include "ResourcePropertyHelper.h"

using std::shared_ptr;
using std::dynamic_pointer_cast;
using std::make_shared;
using std::numeric_limits;
using std::vector;

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

