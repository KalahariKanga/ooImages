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
	
	for (int cx = 0; cx < buffer->getWidth(); cx++)
		for (int cy = 0; cy < buffer->getHeight(); cy++)
		{
			//possibly interpolate
			//possibly could be faster...?
			image->setPixel(cx, cy, buffer->getPixel(cx, cy));
			
		}
}
