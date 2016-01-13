#include "whileExpression.h"
#include "ControlException.h"

whileExpression::whileExpression()
{
	noArguments = 2;
}


whileExpression::~whileExpression()
{
}

Variable whileExpression::evaluate()
{
	while ((bool)(*arguments[0]->getResult().get<float>()))
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