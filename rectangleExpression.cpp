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
	int x1 = *arguments[0]->getResult().get<float>();
	int y1 = *arguments[1]->getResult().get<float>();
	int x2 = *arguments[2]->getResult().get<float>();
	int y2 = *arguments[3]->getResult().get<float>();
	Variable var(Variable::Type::Selection);
	Selection* s = new Selection(is->image->getWidth(), is->image->getHeight());
	for (int cx = 0; cx < is->image->getWidth(); cx++)
		for (int cy = 0; cy < is->image->getHeight(); cy++)
		{
			if (cx < x1 || cx > x2 || cy < y1 || y2 > y2)
				s->setValue(cx, cy, 0);
			else
				s->setValue(cx, cy, 1);//possibly unnecessary 
		}
	var.set<Selection>(s);
	return var;
}