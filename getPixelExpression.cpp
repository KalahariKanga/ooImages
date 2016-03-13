#include "getPixelExpression.h"


getPixelExpression::getPixelExpression()
{
	noArguments = 2;
}


getPixelExpression::~getPixelExpression()
{
}

Variable getPixelExpression::evaluate()
{
	float x = *arguments[0]->getResult().get<Real>();
	float y = *arguments[1]->getResult().get<Real>();
	Variable var(new Colour(store->image->getPixel(x, y)));
	return var;
}
