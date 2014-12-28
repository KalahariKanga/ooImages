#include "PixelModifier.h"


PixelModifier::PixelModifier()
{
}

PixelModifier::PixelModifier(ImageObject* image, Mask* mask)
	:ImageModifier(image, mask)
{

}

PixelModifier::~PixelModifier()
{
}

void PixelModifier::apply()
{
	setup();
	for (int x = 0; x < image->getWidth(); x++)
		for (int y = 0; y < image->getHeight(); y++)
		{
			float v = mask->getValue(x, y);
			Colour old = image->getPixel(x, y);
			Colour n = modifyPixel(x, y);
			buffer->setPixel(x, y, Colour::interpolate(old, n, v));
		}
}

void PixelModifier::setup()
{

}

Colour PixelModifier::modifyPixel(int x, int y)
{
	//
	return Colour(0, 0, 0);
}
