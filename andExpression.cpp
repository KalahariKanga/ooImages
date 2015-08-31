#include "andExpression.h"


andExpression::andExpression()
{
	noArguments = 2;
}


andExpression::~andExpression()
{
}

Variable andExpression::evaluate()
{
	ImageStore* is = ImageStore::get();
	Variable var(Variable::Type::Selection);
	var.selection = new Selection(is->image->getWidth(), is->image->getHeight());

	Variable varA(arguments[0]->evaluate());
	Variable varB(arguments[1]->evaluate());

	Selection* a = varA.moveSelection();
	Selection* b = varB.moveSelection();

	for (int cx = 0; cx < is->image->getWidth(); cx++)
		for (int cy = 0; cy < is->image->getHeight(); cy++)
		{
			if (a->getValue(cx, cy) && b->getValue(cx, cy))
				var.selection->setValue(cx, cy, 1);
			else
				var.selection->setValue(cx, cy, 0);
		}
	return var;
}
