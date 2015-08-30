#include "ImageModifierExpression.h"


ImageModifierExpression::ImageModifierExpression()
{
	ImageStore* store = ImageStore::get();
	image = store->image;
	buffer = new ImageObject(image->getWidth(), image->getHeight());
}


ImageModifierExpression::~ImageModifierExpression()
{
	delete buffer;
}



void ImageModifierExpression::commitBuffer()
{
	ImageStore* is = ImageStore::get(); 
	for (int cx = 0; cx < buffer->getWidth(); cx++)
		for (int cy = 0; cy < buffer->getHeight(); cy++)
		{
			Colour oldC = is->image->getPixel(cx, cy);
			Colour newC = buffer->getPixel(cx, cy);
			float v = is->mask->getValue(cx, cy);
			Colour result = Colour::interpolate(oldC, newC, v);
			//possibly interpolate
			//possibly could be faster...?
			image->setPixel(cx, cy, result);
			
		}
}
