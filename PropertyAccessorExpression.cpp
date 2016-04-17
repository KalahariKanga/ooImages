#include "PropertyAccessorExpression.h"


PropertyAccessorExpression::PropertyAccessorExpression(std::string string) : name(string)
{
	noArguments = 1;
	name.erase(name.end() - 1);
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
	std::string propName = prop->getString();

	//this could be function'd and put into termexpr
	Variable v;
	if (vs->variableExists(name))
		v = vs->getVariable(name);
	else
	{
		auto exp = localVariableExists(name);
		if (exp)
		{
			v = exp->getLocalVariable(name);
		}
		else
			throw new Exception(Exception::ErrorType::UNKNOWN_VARIABLE);
	}

	
	auto resource = v.get<Resource>();
	if (!resource)
		throw new Exception(Exception::ErrorType::ILLEGAL_OPERATOR);

	return Variable(resource->getProperty(propName));

}
