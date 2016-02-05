#include "Real.h"

RESOURCE_DEFINE_STATIC_PROPERTY_MAP(Real)

Real::Real()
{
}


Real::~Real()
{
}

void Real::about()
{
	std::cout << "About\n";
	std::cout << "Real\n";
	std::cout << value << std::endl;
}

void Real::loadProperties()
{

}