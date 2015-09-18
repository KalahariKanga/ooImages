#include "selectExpression.h"


selectExpression::selectExpression()
{
	noArguments = 1;
}


selectExpression::~selectExpression()
{
}

Variable selectExpression::evaluate()
{
	ImageStore* is = ImageStore::get();
	delete is->mask;
	Variable v = arguments.back()->evaluate();
	if (v.type == Variable::Type::Selection)
	{
		is->mask = v.moveSelection();
	}
	else if (v.type == Variable::Type::Mask)
	{
		//this is really horrible. i need to get the hang of smart pointers...
		Mask* m = v.moveMask();
		Selection* s = new Selection(*m, 0);
		delete m;
		is->mask = s;
	}
	else
		throw new Exception(Exception::ErrorType::TYPE_MISMATCH);

	return Variable(Variable::Type::Void);
}
