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
	while((bool)(*arguments[0]->evaluate().get<float>()))
		arguments[1]->evaluate();
	return Variable(Variable::Type::Void);
}