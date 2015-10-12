#pragma once
#include "Resource.h"

class Kernel : public Resource
{
	int size;
	float *data;
public:
	Kernel(int size);
	~Kernel();

	float get(int x, int y);
	void set(int x, int y, float value);
	int getSize();
	void about();
};

