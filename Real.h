#pragma once
#include "ResourcePropertyHelper.h"
class Real :
	public ResourcePropertyHelper<Real>
{
	float value;
public:
	Real();
	~Real();

	float get(){ return value; }
	void set(float v){ value = v; }

	virtual void about();
	static void loadProperties();
};

