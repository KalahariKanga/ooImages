#include "cropExpression.h"


cropExpression::cropExpression()
{
	noArguments = 0;
}


cropExpression::~cropExpression()
{
}

Variable cropExpression::evaluate()
{
	ImageObject* image = ImageStore::get()->image.get();
	Mask* mask = ImageStore::get()->mask.get();

	int minX = image->getWidth();
	int minY = image->getHeight();
	int maxX = 0, maxY = 0;

	for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
		{
			if (mask->getValue(cx, cy))
			{
				if (cx < minX){ minX = cx; }
				if (cy < minY){ minY = cy; }
				if (cx > maxX){ maxX = cx; }
				if (cy > maxY){ maxY = cy; }
			}
		}

	ImageObject* result = new ImageObject(maxX - minX, maxY - minY);

	for (int cx = minX; cx <= maxX; cx++)
		for (int cy = minY; cy <= maxY; cy++)
		{
			if (mask->getValue(cx, cy))
			{
				Colour c = image->getPixel(cx, cy);
				result->setPixel(cx - minX, cy - minY, c);
			}
			else
				result->setPixel(cx - minX, cy - minY, Colour(0, 0, 0, 0));
		}

	Variable var(result);
	return var;
}