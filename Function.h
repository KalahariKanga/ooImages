#pragma once
#include "Resource.h"
#include "Expression.h"
class Function :
	public Resource
{
	Expression* head;
	std::vector<std::string> argumentNames;
	int noArguments;
public:
	Function();
	~Function();
	Variable call(std::vector<Variable> arguments);
};

