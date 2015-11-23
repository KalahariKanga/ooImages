#include "FunctionCallExpression.h"
#include "Function.h"
#include "VariableStore.h"

FunctionCallExpression::FunctionCallExpression(std::string string) : name(string)
{
	noArguments = 1;
	name.erase(name.end() - 1);
}


FunctionCallExpression::~FunctionCallExpression()
{
}

Variable FunctionCallExpression::evaluate()
{
	std::vector<Variable> fnArguments;
	Variable v = VariableStore::get()->getVariable(name);
	Function *fn = v.get<Function>();
	//check arg[0] is [
	for (int c = 0; c < fn->noArguments; c++)
	{
		fnArguments.push_back(arguments[0]->arguments[c]->getResult().duplicate()); //not sure
		//=> call by value...:/
	}
	return fn->call(fnArguments).duplicate();
}