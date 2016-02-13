#pragma once
#include "ResourcePropertyHelper.h"
class Real :
	public ResourcePropertyHelper<Real>
{
	float value;
public:
	Real();
	Real(float v) : value(v)
	{

	}
	~Real();

	float get(){ return value; }
	void set(float v){ value = v; }

	operator float()
	{
		return value;
	}
	float operator=(float v)
	{
		value = v;
		return v;
	}
	virtual void about();
	static void loadProperties();
};

