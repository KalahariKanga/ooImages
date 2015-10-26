#include "Resource.h"
#include "Exception.h"

Resource::Resource()
{
}


Resource::~Resource()
{
}

void Resource::setProperty(std::string name, int* data)
{
	properties[name] = data;
}

float Resource::getProperty(std::string name)
{
	if (properties.find(name) != properties.end())
		return *properties[name];
	else
		throw new Exception(Exception::ErrorType::UNKNOWN_PROPERTY);
}