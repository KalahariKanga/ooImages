#pragma once
#include "core.h"
#include <map>
#include <functional>

class Resource
{
public:
	Resource();
	virtual ~Resource();
	virtual void about() = 0;
	//populate all resource 
	static void loadProperties();
};

