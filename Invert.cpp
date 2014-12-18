#include "Invert.h"

Invert::Invert()
{
}
Invert::Invert(ImageObject* image, Selection* selection)
	:PixelModifier(image,selection)
{
	/*this->image = image;
	this->selection = selection;*/
}


Invert::~Invert()
{
}

void Invert::setup()
{

}

Colour Invert::modifyPixel(int x, int y)
{
	Colour c = image->getPixel(x, y);
	c.r(255 - c.r());
	c.g(255 - c.g());
	c.b(255 - c.b());
	return c;
}