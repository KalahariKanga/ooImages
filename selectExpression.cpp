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

	Variable v = arguments.back()->getResult();
	if (v.type == Variable::Type::Selection)
	{
		is->mask = arguments[0]->getResult().getShared<AbstractMask>();
	}
	else if (v.type == Variable::Type::Mask)
	{
		//this is really horrible. i need to get the hang of smart pointers...
		Mask* m = v.get<Mask>();
		std::shared_ptr<Selection> s(new Selection(*m, 0));
		is->mask = s;
	}
	else
		throw new Exception(Exception::ErrorType::TYPE_MISMATCH);

	return Variable(Variable::Type::Void);
}
