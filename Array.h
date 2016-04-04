#pragma once
#include "ResourcePropertyHelper.h"
#include "Variable.h"
class Array :
	public ResourcePropertyHelper<Array>
{
	std::vector<Variable> vector;
public:
	Array();
	~Array();

	virtual void about();
};

