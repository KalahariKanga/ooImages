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
	float x = *arguments[0]->evaluate().get<float>();
	float y = *arguments[1]->evaluate().get<float>();
	Variable var(Variable::Type::Colour);
	var.set<Colour>(new Colour(ImageStore::get()->image->getPixel(x, y)));
	return var;
}
