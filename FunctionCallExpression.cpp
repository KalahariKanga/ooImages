#include "FunctionCallExpression.h"
#include "VariableStore.h"
#include "SequenceExpression.h"
#include "EndSequenceExpression.h"

FunctionCallExpression::FunctionCallExpression(std::string str) : string(str)
{
	noArguments = 0;
	string.erase(string.end() - 1);
	vs = VariableStore::get();
}


FunctionCallExpression::~FunctionCallExpression()
{
}

Expression* FunctionCallExpression::acquire(std::vector<std::shared_ptr<Expression>>* tokens)
{
	if (!tokens->empty())
		tokens->erase(tokens->begin());

	while (!std::dynamic_pointer_cast<EndSequenceExpression>(tokens->front()))
	{
		if (tokens->empty())
			throw new Exception(Exception::ErrorType::MISMATCHED_BRACKETS);
		arguments.push_back(tokens->front());
		tokens->front()->parent = this;
		++noArguments;
		arguments.back()->acquire(tokens);
	}
	arguments.push_back(tokens->front());
	tokens->front()->parent = this;
	arguments.back()->acquire(tokens);
	return this;
}

Variable FunctionCallExpression::evaluate()
{
	std::vector<Variable> fnArguments;
	Variable v;
	
	if (lastExpression)
		v = lastExpression->getLocalVariable(string);
	else
	{
		lastExpression = localVariableExists(string);
		if (lastExpression)
			v = lastExpression->getLocalVariable(string);
	}
	
	if (vs->variableExists(string))
		v = vs->getVariable(string);

	Function* fn = v.get<Function>();

	for (int c = 0; c < fn->noArguments; c++)
	{
		fnArguments.push_back(arguments[c]->getResult().duplicate());
	}
	return fn->call(fnArguments).duplicate();
}