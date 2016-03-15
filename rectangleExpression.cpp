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
	int x1 = *arguments[0]->getResult().get<Real>();
	int y1 = *arguments[1]->getResult().get<Real>();
	int x2 = *arguments[2]->getResult().get<Real>();
	int y2 = *arguments[3]->getResult().get<Real>();
	Variable var(new Mask(store->image->getWidth(), store->image->getHeight()));
	auto mask = var.get<Mask>();
	for (int cx = 0; cx < store->image->getWidth(); cx++)
		for (int cy = 0; cy < store->image->getHeight(); cy++)
		{
			if (cx < x1 || cx > x2 || cy < y1 || cy > y2)
				mask->setValue(cx, cy, 0);
			else
				mask->setValue(cx, cy, 1);//possibly unnecessary 
		}
	return var;
}