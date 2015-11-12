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
	int width = *arguments[0]->getResult().get<float>();
	int height = *arguments[1]->getResult().get<float>();
	Variable image(Variable::Type::Image);
	image.set<ImageObject>(new ImageObject(width, height));
	return image;
}

