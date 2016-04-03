#pragma once
#include "core.h"
#include "Exception.h"
#include <unordered_map>
#include <functional>

class Resource
{
public:
	Resource();
	virtual ~Resource();
	virtual void about() = 0;
	virtual float getProperty(std::string name) = 0;
	virtual Resource* clone() = 0;
};

