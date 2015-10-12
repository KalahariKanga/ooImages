#include "Kernel.h"


Kernel::Kernel(int size) : size(size)
{
	data = new float[size*size];
}


Kernel::~Kernel()
{
	delete[] data;
}

float Kernel::get(int x, int y)
{
	if (x< size && y < size && x >= 0 && y >= 0)
		return data[size*y + x];
}

void Kernel::set(int x, int y, float value)
{
	if (x < size && y < size && x >= 0 && y >= 0)
		data[size*y + x] = value;
}

int Kernel::getSize()
{
	return size;
}

void Kernel::about()
{
	std::cout << "About\n";
	std::cout << "Size: " << getSize() << "\n";
	std::cout << "Sample: ";
	for (int cy = 0; cy < std::min(10, size); cy++)
	{
		std::cout << std::endl;
		for (int cx = 0; cx < std::min(size, 10); cx++)
			std::cout << get(cx, cy) << " ";
	}
}