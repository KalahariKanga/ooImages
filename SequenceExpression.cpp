#include "SequenceExpression.h"
#include "EndSequenceExpression.h"

SequenceExpression::SequenceExpression()
{
	noArguments = 0;
}


SequenceExpression::~SequenceExpression()
{
}

Expression* SequenceExpression::acquire(std::vector<Expression*>* tokens)
{
	if (!tokens->empty())
		tokens->erase(tokens->begin());

	while (!dynamic_cast<EndSequenceExpression*>(tokens->front()))
	{
		if (tokens->empty())
			throw new Exception(Exception::ErrorType::MISMATCHED_BRACKETS);
		arguments.push_back(tokens->front());
		++noArguments;
		arguments.back()->acquire(tokens);
	}
	return this;
}

Variable SequenceExpression::evaluate()
{
	for (int c = 0; c < noArguments; c++)
		arguments[c]->evaluate();
	return Variable(Variable::Type::Void);
}