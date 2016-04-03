#pragma once
#include "Variable.h"

class VariableStore
{
	std::unordered_map<std::string, Variable> variableMap;
	static VariableStore* instance;
public:
	VariableStore();
	~VariableStore();

	void setVariable(std::string name, Variable data);
	void setArrayVariable(std::string name, int index, Variable data);
	//duplicate and return the variable
	Variable getVariable(std::string name);

	//return variable with same shared ptr
	Variable getRawVariable(std::string name);

	bool legalVariableName(std::string name);
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

