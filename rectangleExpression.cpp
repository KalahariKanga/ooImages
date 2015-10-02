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
	int x1 = *arguments[0]->evaluate().get<float>();
	int y1 = *arguments[1]->evaluate().get<float>();
	int x2 = *arguments[2]->evaluate().get<float>();
	int y2 = *arguments[3]->evaluate().get<float>();
	Variable var(Variable::Type::Selection);
	Selection* s = new Selection(is->image->getWidth(), is->image->getHeight());
	s->toRectangle(x1, y1, x2, y2);
	var.set<Selection>(s);
	return var;
}