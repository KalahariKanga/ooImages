#include "setExpression.h"
#include "ArrayVariableExpression.h"

setExpression::setExpression()
{
	noArguments = 2;
}


setExpression::~setExpression()
{

}

Variable setExpression::evaluate()
{
	Variable var;

	auto term = std::dynamic_pointer_cast<TerminalExpression>(arguments[0]);
	auto arr = std::dynamic_pointer_cast<ArrayVariableExpression>(arguments[0]);

	std::string name = term->getString();
	if (!term)
		throw new Exception(Exception::ErrorType::ILLEGAL_NAME);

	if (VariableStore::get()->legalVariableName(name))
	{
		var = arguments[1]->getResult().duplicate();
		
		if (arr) //if we're setting an array element
		{
			auto exp = localVariableExists(name);
			Variable arrayVariable;
			if (exp) //if the array exists locally
			{
				arrayVariable = exp->getLocalVariable(name);
			}
			else if (VariableStore::get()->variableExists(name)) //if the array exists globally
			{
				arrayVariable = VariableStore::get()->getVariable(name);
			}
			else
				throw new Exception(Exception::ErrorType::UNKNOWN_VARIABLE);

			auto arrayResource = arrayVariable.get<Array>();
			arrayResource->set(arr->getIndex(), var);
		}
		else //not an array element
		{
			if (parent)
				parent->setLocalVariable(name, var);
			else
				VariableStore::get()->setVariable(name, var);
		}
	}
	else
		throw new Exception(Exception::ErrorType::ILLEGAL_NAME);

	return var;
}
