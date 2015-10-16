#include "cropExpression.h"


cropExpression::cropExpression()
{
}


cropExpression::~cropExpression()
{
}

Variable cropExpression::evaluate()
{
	ImageObject* image = ImageStore::get()->image.get();
	AbstractMask* mask = ImageStore::get()->mask.get();
	int minX = image->getWidth();
	int minY = image->getHeight();
	int maxX = 0, maxY = 0;

	/*for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
		{
			if (mask->getValue(cx, cy))
			{
				if (cx < minX){ minX = cx; }
				if (cy < minY){ minY = cy; }
				if (cx > maxX){ maxX = cx; }
				if (cy > maxY){ maxY = cy; }
			}
		}*/
	for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
		{
			if (!mask->getValue(cx, cy))
			{
				Colour c = image->getPixel(cx, cy);
				c.a(0);
				image->setPixel(cx, cy, c);
			}
		}

	//return cropped image
	return Variable(Variable::Type::Void);
}
