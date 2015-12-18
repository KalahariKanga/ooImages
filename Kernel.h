#pragma once
#include "ResourcePropertyHelper.h"

class Kernel : public ResourcePropertyHelper<Kernel>
{
	int size;
	float *data;
public:
	Kernel(int size);
	Kernel(const Kernel& obj);
	~Kernel();

	float get(int x, int y);
	void set(int x, int y, float value);
	int getSize();
	void about();

	static void loadProperties();
};

