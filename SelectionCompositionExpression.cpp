#include "SelectionCompositionExpression.h"


SelectionCompositionExpression::SelectionCompositionExpression()
{
	noArguments = 2;
}


SelectionCompositionExpression::~SelectionCompositionExpression()
{
}

Variable SelectionCompositionExpression::evaluate()
{
	ImageStore* is = ImageStore::get();
	Variable var(Variable::Type::Selection);
	Selection* s = new Selection(is->image->getWidth(), is->image->getHeight());

	Variable varA(arguments[0]->evaluate());
	Variable varB(arguments[1]->evaluate());

	Selection* a = varA.get<Selection>();
	Selection* b = varB.get<Selection>();

	for (int cx = 0; cx < is->image->getWidth(); cx++)
		for (int cy = 0; cy < is->image->getHeight(); cy++)
		{
			if (op(a->getValue(cx, cy),b->getValue(cx, cy)))
				s->setValue(cx, cy, 1);
			else
				s->setValue(cx, cy, 0);
		}
	return var;
}
