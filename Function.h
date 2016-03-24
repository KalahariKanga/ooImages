#pragma once
#include "ResourcePropertyHelper.h"
#include "Expression.h"
class Function :
	public ResourcePropertyHelper<Function>
{
	std::shared_ptr<Expression> head;
	std::vector<std::string> argumentNames;
	
public:
	
	Function(std::shared_ptr<Expression> head, std::vector<std::string> argumentNames);
	Function(const Function& obj);
	~Function();
	Variable call(std::vector<Variable> arguments);
	int noArguments;
	virtual void about();

	static void loadProperties();
	
};

