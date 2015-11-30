#include "Resource.h"
#include "Exception.h"

Resource::Resource()
{
}


Resource::~Resource()
{
}

//void Resource::setProperty(std::string name, std::function<float(void)> fn)
//{
//	properties[name] = fn;
//}
//
//float Resource::getProperty(std::string name)
//{
//	if (properties.find(name) != properties.end())
//		return properties[name]();
//	else
//		throw new Exception(Exception::ErrorType::UNKNOWN_PROPERTY);
//}