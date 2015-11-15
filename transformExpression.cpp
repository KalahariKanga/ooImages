#include "transformExpression.h"


transformExpression::transformExpression()
{
	noArguments = 2;
}


transformExpression::~transformExpression()
{
	
}

Variable transformExpression::evaluate()
{
	for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
		{
			Colour p = image->getPixel(cx, cy);
			setLocalVariable("x", cx);
			setLocalVariable("y", cy);
			setLocalVariable("h", p.h());
			setLocalVariable("s", p.s());
			setLocalVariable("v", p.v());
			setLocalVariable("r", p.r());
			setLocalVariable("g", p.g());
			setLocalVariable("b", p.b());
			float nx = *arguments[0]->getResult().get<float>();
			float ny = *arguments[1]->getResult().get<float>();
			buffer->setPixel(cx, cy, image->getPixel(nx, ny));
		}
	commitBuffer();
	return Variable(Variable::Type::Void);
}
