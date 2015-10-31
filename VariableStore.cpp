#include "VariableStore.h"
#include <cctype>

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
	auto v = variableMap.find(name);
	if (v == variableMap.end())
		throw new Exception(Exception::ErrorType::UNKNOWN_VARIABLE);
	else
		return v->second.duplicate();
}

bool VariableStore::legalVariableName(std::string name)
{
	
	//TODO: check substrings for reserved words
	return 1;
}