#pragma once
#include "Resource.h"

#define RESOURCE_DEFINE_STATIC_PROPERTY_MAP(NAME) template <> std::map<std::string, std::function<float(NAME*)>> ResourcePropertyHelper<NAME>::properties;	


template <class Derived>
class ResourcePropertyHelper :
	public Resource
{
protected:
	static std::map<std::string, std::function<float(Derived*)>> properties;
public:
	ResourcePropertyHelper() = default;
	~ResourcePropertyHelper() = default;

	virtual float getProperty(std::string name)
	{
		if (properties.find(name) != properties.end())
			return properties[name]((Derived*)this);
		else
			throw new Exception(Exception::ErrorType::UNKNOWN_PROPERTY);
	}
	static void setProperty(std::string name, std::function<float(Derived*)> fn)
	{
		properties[name] = fn;
	}

	Resource* clone()
	{
		return new Derived(static_cast<Derived const&>(*this));
	}
};

