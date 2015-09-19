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
	float x = arguments[0]->evaluate().real;
	float y = arguments[1]->evaluate().real;
	Colour col = ImageStore::get()->image->getPixel(x, y);
	Variable var(Variable::Type::Colour);
	var.colour = &col;
	return var;
}
