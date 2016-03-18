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

void VariableStore::setArrayVariable(std::string name, int index, Variable var)
{
	//name.erase(name.end() - 1);
	std::string newname = std::to_string(index) + name;
	variableMap[newname] = var;
}

Variable VariableStore::getVariable(std::string name)
{
	auto v = variableMap.find(name);
	if (v == variableMap.end())
		throw new Exception(Exception::ErrorType::UNKNOWN_VARIABLE);
	else
		return v->second;
		//return v->second.duplicate();
}

Variable VariableStore::getRawVariable(std::string name)
{
	auto v = variableMap.find(name);
	if (v == variableMap.end())
		throw new Exception(Exception::ErrorType::UNKNOWN_VARIABLE);
	else
		return v->second;
}

bool VariableStore::legalVariableName(std::string name)
{
	if (!isalpha(name[0]))
		return 0;
	//TODO: check substrings for reserved words
	return 1;
}