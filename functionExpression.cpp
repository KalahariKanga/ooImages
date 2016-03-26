#include "functionExpression.h"
#include "Function.h"
#include "SequenceExpression.h"
#include "TerminalExpression.h"
functionExpression::functionExpression()
{
	noArguments = 0;
	optimisable = 0;
}


functionExpression::~functionExpression()
{
}

Expression* functionExpression::acquire(std::vector<std::shared_ptr<Expression>>* tokens)
{
	if (!tokens->empty())
		tokens->erase(tokens->begin());
	while (!std::dynamic_pointer_cast<SequenceExpression>(tokens->front()))
	{
		if (tokens->empty())
			throw new Exception(Exception::ErrorType::INSUFFICIENT_ARGUMENTS);
		arguments.push_back(tokens->front());
		tokens->front()->parent = this;
		arguments.back()->acquire(tokens);
		++noArguments;
	}
	arguments.push_back(tokens->front());
	tokens->front()->parent = this;
	arguments.back()->acquire(tokens);

	return this;
}

Variable functionExpression::evaluate()
{
	//get argument names
	int c = 0;
	std::vector<std::string> argumentNames;
	while (1)
	{
		auto argumentNameExpr = std::dynamic_pointer_cast<TerminalExpression>(arguments[c]);
		if (!argumentNameExpr)
			break;
		argumentNames.push_back(argumentNameExpr->getName());
		++c;
	}
	
	Variable var(new Function(arguments[c], argumentNames));
	return var;
}