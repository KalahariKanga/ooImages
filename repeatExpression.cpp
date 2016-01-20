#include "repeatExpression.h"
#include "ControlException.h"

repeatExpression::repeatExpression()
{
	noArguments = 2;
}


repeatExpression::~repeatExpression()
{
}

Variable repeatExpression::evaluate()
{
	int n = (int)(*arguments[0]->getResult().get<float>());
	for (int c = 0; c < n; c++)
	{
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
	return Variable(Variable::Type::Void);
}
