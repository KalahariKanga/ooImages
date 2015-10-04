#pragma once
#include <map>
#include "Variable.h"

class VariableStore
{
	std::map<std::string, Variable> variableMap;
	static VariableStore* instance;
public:
	VariableStore();
	~VariableStore();

	void setVariable(std::string name, Variable data);
	Variable getVariable(std::string name);
	bool variableExists(std::string name)
	{
		return (variableMap.find(name) != variableMap.end());
	}

	static VariableStore* get()
	{
		if (instance)
			return instance;
		return (instance = new VariableStore());
	}
};
