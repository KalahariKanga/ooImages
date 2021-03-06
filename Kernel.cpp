#include "Kernel.h"

RESOURCE_DEFINE_STATIC_PROPERTY_MAP(Kernel)

Kernel::Kernel(int size) : size(size)
{
	data = new float[size*size];
}

Kernel::Kernel(const Kernel& obj)
{
	size = obj.size;
	data = new float[size*size];
	for (int cx = 0; cx < size; cx++)
		for (int cy = 0; cy < size; cy++)
			data[size*cy + cx] = obj.data[size*cy + cx];
}

Kernel::~Kernel()
{
	delete[] data;
}

float Kernel::get(int x, int y)
{
	if (x < size && y < size && x >= 0 && y >= 0)
		return data[size*y + x];
	else
		return 0;
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
	std::cout << "Kernel\n";
	std::cout << "Size: " << getSize() << "\n";
	std::cout << "Sample: ";
	for (int cy = 0; cy < std::min(10, size); cy++)
	{
		std::cout << std::endl;
		for (int cx = 0; cx < std::min(size, 10); cx++)
			std::cout << get(cx, cy) << " ";
	}
	std::cout << "\n";
}

void Kernel::loadProperties()
{
	setProperty("size", [](Kernel* k){return k->getSize(); });
}