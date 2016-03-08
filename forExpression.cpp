#include "forExpression.h"
#include "TerminalExpression.h"
#include "ControlException.h"

forExpression::forExpression()
{
	noArguments = 5;
	//variable, from, to, step, sequence
}


forExpression::~forExpression()
{
}

Variable forExpression::evaluate()
{
	auto term = dynamic_pointer_cast<TerminalExpression>(arguments[0]);
	if (!term)
	{
		throw new Exception(Exception::ErrorType::ILLEGAL_NAME);
	}

	float from = *arguments[1]->getResult().get<Real>();
	float c = from;
	float previous = from;

	while (1)
	{
		arguments[2]->setLocalVariable(term->getString(), Variable(c));
		arguments[3]->setLocalVariable(term->getString(), Variable(c));
		arguments[4]->setLocalVariable(term->getString(), Variable(c));
		try
		{
			arguments[4]->getResult();
		}
		catch (ControlException e)
		{
			if (e.type == ControlException::Type::BREAK)
				break;
			if (e.type == ControlException::Type::CONTINUE)
				continue;
		}

		float to = *arguments[2]->getResult().get<Real>();
		float step = *arguments[3]->getResult().get<Real>();
		c += step;
		if ((previous < to && c >= to) || (previous > to && c <= to))
			break;
		
		previous = c;
	}
	return Variable();
}