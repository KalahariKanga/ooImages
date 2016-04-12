#include "SequenceExpression.h"
#include "EndSequenceExpression.h"

SequenceExpression::SequenceExpression()
{
	noArguments = 0;
	optimisable = 0;
}


SequenceExpression::~SequenceExpression()
{
}

Expression* SequenceExpression::acquire(std::vector<std::shared_ptr<Expression>>* tokens)
{
	if (!tokens->empty())
		tokens->erase(tokens->begin());

	if (tokens->empty())
		throw new Exception(Exception::ErrorType::INSUFFICIENT_ARGUMENTS);

	while (!std::dynamic_pointer_cast<EndSequenceExpression>(tokens->front()))
	{
		if (tokens->empty())
			throw new Exception(Exception::ErrorType::MISMATCHED_BRACKETS);
		arguments.push_back(tokens->front());
		tokens->front()->parent = this;
		++noArguments;
		arguments.back()->acquire(tokens);
	}

	//the ] is sort of an argument - clear it from the token list anyway
	if (tokens->empty())
		throw new Exception(Exception::ErrorType::INSUFFICIENT_ARGUMENTS);
	arguments.push_back(tokens->front());
	tokens->front()->parent = this;
	arguments.back()->acquire(tokens);
	return this;
}

Variable SequenceExpression::evaluate()
{
	try
	{
		for (int c = 0; c < noArguments; c++)
			arguments[c]->getResult();
	}
	catch (Variable v)
	{
		return v;
	}
	return Variable();
}