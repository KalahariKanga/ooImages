#include "ifExpression.h"
#include "elseExpression.h"

ifExpression::ifExpression()
{
	noArguments = 2;
	optimisable = 0;
}


ifExpression::~ifExpression()
{
}

Expression* ifExpression::acquire(std::vector<std::shared_ptr<Expression>>* tokens)
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
	if (std::dynamic_pointer_cast<elseExpression>(tokens->front()))
	{
		hasElse = true;
		++noArguments;
		arguments.push_back(tokens->front());
		arguments.back()->acquire(tokens);
	}
	return this;

}

Variable ifExpression::evaluate()
{
	//TODO: reevaluate even if constant?
	if (*arguments[0]->getResult().get<Real>())
	{
		arguments[1]->getResult();
	}
	else
	{
		if (hasElse)
		{
			arguments[2]->getResult();
		}
	}
	return Variable();
}