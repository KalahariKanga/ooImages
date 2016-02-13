#include "FunctionCallExpression.h"
#include "Function.h"
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

void FunctionCallExpression::setLocalVariable(std::string name, Variable var)
{
	localVariables[name] = var;
	for (int c = 0; c < noArguments; c++)
		arguments[c]->setLocalVariable(name, var);
}
void FunctionCallExpression::setLocalVariable(std::string name, float* ptr)
{
	localPointers[name] = ptr;
	for (int c = 0; c < noArguments; c++)
		arguments[c]->setLocalVariable(name, ptr);
}

Expression* FunctionCallExpression::acquire(std::vector<shared_ptr<Expression>>* tokens)
{
	if (!tokens->empty())
		tokens->erase(tokens->begin());

	while (!dynamic_pointer_cast<EndSequenceExpression>(tokens->front()))
	{
		if (tokens->empty())
			throw new Exception(Exception::ErrorType::MISMATCHED_BRACKETS);
		arguments.push_back(tokens->front());
		++noArguments;
		arguments.back()->acquire(tokens);
	}
	arguments.push_back(tokens->front());
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