#include "dilateExpression.h"
#include "ImageStore.h"

dilateExpression::dilateExpression()
{
	noArguments = 1;
}


dilateExpression::~dilateExpression()
{
}

Variable dilateExpression::evaluate()
{
	Mask* mask = ImageStore::get()->mask.get();
	Mask* newMask = new Mask(mask->width, mask->height);
	Kernel* k = arguments[0]->getResult().get<Kernel>();
	int ks = k->getSize();

	for (int cx = 0; cx < mask->width; cx++)
		for (int cy = 0; cy < mask->height; cy++)
		{
			float max = numeric_limits<float>::min();
			for (int kx = 0; kx <= ks; kx++)
				for (int ky = 0; ky <= ks; ky++)
				{
					float v = mask->getValue(cx + kx - ks / 2, cy + ky - ks / 2) + k->get(kx, ky);
					if (v > max)
						max = v;
				}
			newMask->setValue(cx, cy, max);
		}

	//potential memory leak again
	ImageStore::get()->mask.reset(newMask);
	return Variable();
}
