#pragma once
#include "Resource.h"

class Kernel : public Resource
{
	int size;
	int *data;
public:
	Kernel(int size);
	~Kernel();

	int get(int x, int y);
	void set(int x, int y, int value);
	int getSize();
	void about();
};

