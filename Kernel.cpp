#include "Kernel.h"


Kernel::Kernel(int size) : size(size)
{
	data = new int[size*size];
}


Kernel::~Kernel()
{
	delete[] data;
}

int Kernel::get(int x, int y)
{
	if (x< size && y < size && x >= 0 && y >= 0)
		return data[size*y + x];
}

void Kernel::set(int x, int y, int value)
{
	if (x < size && y < size && x >= 0 && y >= 0)
		data[size*y + x] = value;
}

int Kernel::getSize()
{
	return size;
}