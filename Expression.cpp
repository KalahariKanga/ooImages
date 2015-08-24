#include "Expression.h"


Expression::Expression()
{
}


Expression::~Expression()
{
	for (auto a : arguments)
	{
		delete a;
	}
}

void Expression::addLocalVariable(std::string name, float* ptr)
{
	for (auto a : arguments)
		a->addLocalVariable(name, ptr);
}

Expression* Expression::acquire(std::vector<Expression*>* tokens)
{
	if (!tokens->empty())
		tokens->erase(tokens->begin());

	for (int c = 0; c < noArguments; c++)
	{
		if (tokens->empty())
			throw new Exception(Exception::ErrorType::INSUFFICIENT_ARGUMENTS);
		arguments.push_back(tokens->front());
		arguments.back()->acquire(tokens);
	}
	return this;
}