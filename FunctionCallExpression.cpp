#include "FunctionCallExpression.h"
#include "VariableStore.h"
#include "SequenceExpression.h"
#include "EndSequenceExpression.h"

FunctionCallExpression::FunctionCallExpression(std::string string) : name(string)
{
	noArguments = 0;
	name.erase(name.end() - 1);
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
	if (vs->variableExists(name))
		v = vs->getVariable(name);

	if (localVariables.find(name) != localVariables.end())
	{
		v = localVariables[name];
	}

	Function* fn = v.get<Function>();

	for (int c = 0; c < fn->noArguments; c++)
	{
		fnArguments.push_back(arguments[c]->getResult().duplicate());
	}
	return fn->call(fnArguments).duplicate();
}