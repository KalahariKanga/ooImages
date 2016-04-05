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
	Variable get(int i);
	void set(int i, Variable var);
	virtual void about();
};

