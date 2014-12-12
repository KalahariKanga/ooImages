#include "Invert.h"

Invert::Invert()
{
}
Invert::Invert(ImageObject* image, Selection* selection)
	:ImageModifier(image,selection)
{
	/*this->image = image;
	this->selection = selection;*/
}


Invert::~Invert()
{
}

void Invert::apply()
{
	for (int x = 0; x < image->getWidth(); x++)
		for (int y = 0; y < image->getHeight(); y++)
			if (selection->getValue(x,y))
			{
				Colour c = image->getPixel(x, y);
				c.r(255 - c.r());
				c.g(255 - c.g());
				c.b(255 - c.b());
				buffer->setPixel(x, y, c);
			}
			else
			{
				Colour c = image->getPixel(x, y);
				buffer->setPixel(x, y, c);
			}
}