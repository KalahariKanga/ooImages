#pragma once
#include "core.h"
#include <map>
#include <functional>

class Resource
{
	std::map<std::string, std::function<float(void)>> properties;
public:
	Resource();
	virtual ~Resource();
	virtual void about() = 0;
	void setProperty(std::string name, std::function<float(void)>);
	float getProperty(std::string name);
};

