#include "Array.h"

RESOURCE_DEFINE_STATIC_PROPERTY_MAP(Array);

Array::Array()
{
}


Array::~Array()
{
}

Variable Array::get(int i)
{
	//try catch
	return vector.at(i);
}

void Array::set(int i, Variable var)
{
	//also catch
	if (i >= vector.size())
		vector.resize(i+1);
	vector[i] = var;
}

void Array::about()
{
	std::cout << "About\n";
	std::cout << "Array\n";
	std::cout << "Size: " << vector.size() << "\n";
}