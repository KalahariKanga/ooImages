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
	int x1 = *arguments[0]->getResult().get<Real>();
	int y1 = *arguments[1]->getResult().get<Real>();
	int x2 = *arguments[2]->getResult().get<Real>();
	int y2 = *arguments[3]->getResult().get<Real>();
	Variable var(Variable::Type::Mask);
	Mask* s = new Mask(is->image->getWidth(), is->image->getHeight());
	for (int cx = 0; cx < is->image->getWidth(); cx++)
		for (int cy = 0; cy < is->image->getHeight(); cy++)
		{
			if (cx < x1 || cx > x2 || cy < y1 || y2 > y2)
				s->setValue(cx, cy, 0);
			else
				s->setValue(cx, cy, 1);//possibly unnecessary 
		}
	var.set<Mask>(s);
	return var;
}