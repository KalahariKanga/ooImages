#include "PixelModifier.h"


PixelModifier::PixelModifier()
{
}

PixelModifier::PixelModifier(ImageObject* image, Selection* selection)
	:ImageModifier(image, selection)
{

}

PixelModifier::~PixelModifier()
{
}

void PixelModifier::apply()
{
	for (int x = 0; x < image->getWidth(); x++)
		for (int y = 0; y < image->getHeight(); y++)
			if (selection->getValue(x, y))
			{
				Colour c = modifyPixel(x, y);
				buffer->setPixel(x, y, c);
			}
			else
			{
				Colour c = image->getPixel(x, y);
				buffer->setPixel(x, y, c);
			}
}

Colour PixelModifier::modifyPixel(int x, int y)
{
	//
	return Colour(0, 0, 0);
}
