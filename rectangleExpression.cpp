#include "rectangleExpression.h"


rectangleExpression::rectangleExpression()
{
	noArguments = 4;
}


rectangleExpression::~rectangleExpression()
{

}

Variable rectangleExpression::evaluate()
{
	ImageStore* is = ImageStore::get();
	int x1 = arguments[0]->evaluate().real;
	int y1 = arguments[1]->evaluate().real;
	int x2 = arguments[2]->evaluate().real;
	int y2 = arguments[3]->evaluate().real;
	Variable var(Variable::Type::Selection);
	var.selection = new Selection(is->image->getWidth(), is->image->getHeight());
	var.selection->toRectangle(x1, y1, x2, y2);
	return var;
}