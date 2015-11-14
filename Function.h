#pragma once
#include "Resource.h"
#include "Expression.h"
class Function :
	public Resource
{
	
	
public:
	shared_ptr<Expression> head;
	std::vector<std::string> argumentNames;
	Function(shared_ptr<Expression> head, std::vector<std::string> argumentNames);
	~Function();
	Variable call(std::vector<Variable> arguments);
	int noArguments;
	virtual void about();
};

