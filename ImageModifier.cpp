#include "ImageModifier.h"

ImageModifier::ImageModifier()
{
}
ImageModifier::ImageModifier(ImageObject* image, AbstractMask* mask)
{
	buffer = new ImageObject(image->getWidth(), image->getHeight());
	this->image = image;
	this->mask = mask;
}


ImageModifier::~ImageModifier()
{
	delete buffer;
}

void ImageModifier::modify()
{
	apply();
	for (int x = 0; x < image->getWidth(); x++)
		for (int y = 0; y < image->getHeight(); y++)
			image->setPixel(x, y, buffer->getPixel(x, y));
}

void ImageModifier::apply()
{
	//virtual
}