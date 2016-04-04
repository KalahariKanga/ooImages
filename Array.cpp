#include "Array.h"

RESOURCE_DEFINE_STATIC_PROPERTY_MAP(Array);

Array::Array()
{
}


Array::~Array()
{
}

void Array::about()
{
	std::cout << "About\n";
	std::cout << "Array\n";
	std::cout << "Size: " << vector.size() << "\n";
}