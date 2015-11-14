#pragma once
#include "Resource.h"
#include "Expression.h"
class Function :
	public Resource
{
	shared_ptr<Expression> head;
	std::vector<std::string> argumentNames;
	int noArguments;
public:
	Function(shared_ptr<Expression> head, std::vector<std::string> argumentNames);
	~Function();
	Variable call(std::vector<Variable> arguments);
	virtual void about();
};

