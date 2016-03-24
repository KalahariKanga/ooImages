#include "PropertyAccessorExpression.h"


PropertyAccessorExpression::PropertyAccessorExpression(std::string string) : varName(string)
{
	noArguments = 1;
	varName.erase(varName.end() - 1);
}


PropertyAccessorExpression::~PropertyAccessorExpression()
{
}

Variable PropertyAccessorExpression::evaluate()
{
	auto prop = std::dynamic_pointer_cast<TerminalExpression>(arguments[0]);
	if (!prop)
	{
		throw new Exception(Exception::ErrorType::UNKNOWN_PROPERTY);
	}
	std::string propName = prop->getName();

	//this could be function'd and put into termexpr
	Variable v;
	if (vs->variableExists(varName))
		v = vs->getVariable(varName);
	else if (localVariables.find(varName) != localVariables.end())
	{
		v = localVariables[varName];
	}
	else
		throw new Exception(Exception::ErrorType::UNKNOWN_VARIABLE);

	
	auto resource = v.get<Resource>();
	if (!resource)
		throw new Exception(Exception::ErrorType::ILLEGAL_OPERATOR);

	return Variable(resource->getProperty(propName));

}
