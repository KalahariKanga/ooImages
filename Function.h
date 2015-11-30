#pragma once
#include "ResourcePropertyHelper.h"
#include "Expression.h"
class Function :
	public ResourcePropertyHelper<Function>
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

