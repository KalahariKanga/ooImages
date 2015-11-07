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

Variable Expression::getResult()
{
	if (isConstant && optimisable)
	{
		if (!hasConstantValue)
		{
			hasConstantValue = 1;
			constantValue = evaluate();
		}
		return constantValue;
	}
	else
		return evaluate();
}

bool Expression::calculateConstancy()
{
	isConstant = 1;
	for (auto a : arguments)
	{
		if (!a->calculateConstancy())
		{
			isConstant = 0;
		}
	}
	return isConstant;
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