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
	float x = *arguments[0]->getResult().get<float>();
	float y = *arguments[1]->getResult().get<float>();
	Variable var(Variable::Type::Colour);
	var.set<Colour>(new Colour(ImageStore::get()->image->getPixel(x, y)));
	return var;
}
