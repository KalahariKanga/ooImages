#include "createImageExpression.h"


createImageExpression::createImageExpression()
{
	noArguments = 2;
}


createImageExpression::~createImageExpression()
{
}

Variable createImageExpression::evaluate()
{
	int width = *arguments[0]->getResult().get<Real>();
	int height = *arguments[1]->getResult().get<Real>();
	Variable image(Variable::Type::Image);
	image.set<ImageObject>(new ImageObject(width, height));
	return image;
}

