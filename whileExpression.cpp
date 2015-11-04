#include "whileExpression.h"


whileExpression::whileExpression()
{
	noArguments = 2;
}


whileExpression::~whileExpression()
{
}

Variable whileExpression::evaluate()
{
	while((bool)(*arguments[0]->getResult().get<float>()))
		arguments[1]->getResult();
	return Variable(Variable::Type::Void);
}