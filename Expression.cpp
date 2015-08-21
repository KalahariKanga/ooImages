#include "Expression.h"


Expression::Expression()
{
}


Expression::~Expression()
{
}

Expression* Expression::acquire(std::vector<Expression*>* tokens)
{
	if (!tokens->empty())
		tokens->erase(tokens->begin());

	for (int c = 0; c < noArguments; c++)
	{
			arguments.push_back(tokens->front());
			arguments.back()->acquire(tokens);
	}
	return this;
}