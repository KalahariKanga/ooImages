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
	try
	{
		return vector.at(i);
	}
	catch (std::out_of_range)
	{
		throw new Exception(Exception::ErrorType::ARRAY_ERROR);
	}
}

void Array::set(int i, Variable var)
{
	
	if (i >= vector.size())
	{
		try
		{
			vector.resize(i + 1);
		}
		catch (std::bad_alloc)
		{
			throw new Exception(Exception::ErrorType::ARRAY_ERROR);
		}
	}
	vector[i] = var;
}

int Array::size()
{
	return vector.size();
}

void Array::about()
{
	std::cout << "About\n";
	std::cout << "Array\n";
	std::cout << "Size: " << vector.size() << "\n";
}