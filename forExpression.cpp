#include "forExpression.h"
#include "TerminalExpression.h"


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
	float from = *arguments[1]->getResult().get<float>();
	float to = *arguments[2]->getResult().get<float>();
	float step = *arguments[3]->getResult().get<float>();

	float c;
	arguments[4]->setLocalVariable(term->getString(), &c);

	if (from <= to && step > 0)
		for (c = from; c < to; c += step)
		{
			arguments[4]->evaluate();
		}
	else if (from >= to && step < 0)
		for (c = from; c > to; c += step)
		{
			arguments[4]->evaluate();
		}
	else
		throw new Exception(Exception::ErrorType::LOOP_ERROR);
	return Variable(Variable::Type::Void);
}