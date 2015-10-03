#include "VariableStore.h"

VariableStore* VariableStore::instance;
VariableStore::VariableStore()
{
}


VariableStore::~VariableStore()
{
}

void VariableStore::setVariable(std::string name, Variable var)
{
	variableMap[name] = var;
}

Variable VariableStore::getVariable(std::string name)
{
	//TODO:exception
	return variableMap[name].duplicate();
}