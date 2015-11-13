#include "Function.h"


Function::Function()
{
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