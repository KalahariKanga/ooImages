#pragma once
#include "core.h"
#include <map>

class Resource
{
	std::map<std::string, int*> properties;
public:
	Resource();
	~Resource();
	virtual void about() = 0;
	void setProperty(std::string name, int* data);
	float getProperty(std::string name);
};

