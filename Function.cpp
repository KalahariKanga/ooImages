#include "Function.h"


Function::Function(shared_ptr<Expression> head, std::vector<std::string> argumentNames) : head(head), argumentNames(argumentNames)
{
	noArguments = argumentNames.size();
}


Function::~Function()
{
}

Variable Function::call(std::vector<Variable> arguments)
{
	for (int c = 0; c < noArguments; c++)
	{
		//head->addLocalVariable(argumentNames[c], arguments[c]);
	}
	return head->evaluate();
}

void Function::about()
{
	std::cout << "About Function\n";
}