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
	if (parent && parent->localVariableExists(name))
		parent->setLocalVariable(name, var);
	else
		localVariables[name] = var;
}

void Expression::setLocalVariable(std::string name, float* val)
{
	if (parent && parent->localVariableExists(name))
		parent->setLocalVariable(name, val);
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

bool Expression::localVariableExists(std::string name)
{
	if (localVariables.find(name) != localVariables.end())
		return true;
	if (localPointers.find(name) != localPointers.end())
		return true;
	if (parent)
		return parent->localVariableExists(name);
	return false;
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