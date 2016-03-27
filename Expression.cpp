#include "Expression.h"
#include <algorithm>

ImageStore* const Expression::store = ImageStore::get();

Expression::Expression()
{
}


Expression::~Expression()
{
}

Variable Expression::getResult()
{
	if (!constancyOptimisation)
		return evaluate();

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

void Expression::setLocalVariable(std::string name, Variable var)
{
	auto exp = localVariableExists(name);
	if (exp)
		exp->localVariables[name] = var;
	else
		localVariables[name] = var;
}

void Expression::setLocalVariable(std::string name, float* val)
{
	auto exp = localVariableExists(name);
	if (exp)
		exp->localPointers[name] = val;
	else
		localPointers[name] = val;
}

Variable Expression::getLocalVariable(std::string name)
{
	if (localVariables.find(name) != localVariables.end())
		return localVariables[name];
	if (localPointers.find(name) != localPointers.end())
		return Variable(*localPointers[name]);
	if (parent)
		return parent->getLocalVariable(name);
	throw new Exception(Exception::ErrorType::UNKNOWN_VARIABLE);
}

Expression* Expression::localVariableExists(std::string name)
{
	if (localVariables.find(name) != localVariables.end())
		return this;
	if (localPointers.find(name) != localPointers.end())
		return this;
	if (parent)
		return parent->localVariableExists(name);
	return nullptr;
}

Expression* Expression::acquire(std::vector<std::shared_ptr<Expression>>* tokens)
{
	if (!tokens->empty())
		tokens->erase(tokens->begin());

	for (int c = 0; c < noArguments; c++)
	{
		if (tokens->empty())
			throw new Exception(Exception::ErrorType::INSUFFICIENT_ARGUMENTS);
		arguments.push_back(tokens->front());
		tokens->front()->parent = this;
		arguments.back()->acquire(tokens);
	}
	return this;
}