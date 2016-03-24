#include "Function.h"

RESOURCE_DEFINE_STATIC_PROPERTY_MAP(Function)

Function::Function(std::shared_ptr<Expression> head, std::vector<std::string> argumentNames) : head(head), argumentNames(argumentNames)
{
	noArguments = argumentNames.size();
}

Function::Function(const Function& obj)
{
	head = obj.head;
	argumentNames = obj.argumentNames;
	noArguments = argumentNames.size();
}

Function::~Function()
{
}

Variable Function::call(std::vector<Variable> arguments)
{
	for (int c = 0; c < noArguments; c++)
	{
		head->setLocalVariable(argumentNames[c], arguments[c]);
	}
	return head->evaluate();
}

void Function::about()
{
	std::cout << "About\n";
	std::cout << "Function\n";
	std::cout << "Arguments: ";
	for (auto s : argumentNames)
		std::cout << s << " ";
	std::cout << "\n";
}

void Function::loadProperties()
{
	setProperty("argc", [](Function* f){return f->noArguments; });
}