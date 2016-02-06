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
	float to = *arguments[2]->getResult().get<Real>();
	float step = *arguments[3]->getResult().get<Real>();

	Real counter;
	arguments[4]->setLocalVariable(term->getString(), Variable(counter));

	//this could definitely be neater
	if (from <= to && step > 0)
		for (float c = from; c < to; c += step)
		{
			counter = c;
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
		}
	else if (from >= to && step < 0)
		for (float c = from; c > to; c += step)
		{
			counter = c;
			try
			{
				arguments[1]->getResult();
			}
			catch (ControlException e)
			{
				if (e.type == ControlException::Type::BREAK)
					break;
				if (e.type == ControlException::Type::CONTINUE)
					continue;
			}
		}
	else
		throw new Exception(Exception::ErrorType::LOOP_ERROR);
	return Variable(Variable::Type::Void);
}