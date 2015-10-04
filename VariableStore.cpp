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
	//TODO: exception
	return variableMap[name].duplicate();
}

std::vector<std::string> VariableStore::getRealVariableNames()
{
	std::vector<std::string> list;
	for (auto v : variableMap)
	{
		if (v.second.type == Variable::Type::Real)
			list.push_back(v.first);
	}
	return list;
}