#include "ImageModifierExpression.h"


ImageModifierExpression::ImageModifierExpression()
{
	ImageStore* store = ImageStore::get();
	image = store->getImage();
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

			float v = is->mask->getValue(cx, cy);
			if (v == 0)
			{
				image->setPixel(cx, cy, is->image->getPixel(cx, cy));
				continue;
			}
			if (v == 1)
			{
				image->setPixel(cx, cy, buffer->getPixel(cx, cy));
				continue;
			}

			Colour oldC = is->image->getPixel(cx, cy);
			Colour newC = buffer->getPixel(cx, cy);
			Colour result = Colour::interpolate(oldC, newC, v);
			//possibly could be faster...?
			image->setPixel(cx, cy, result);
			
		}
}
