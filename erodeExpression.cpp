#include "erodeExpression.h"
#include "ImageStore.h"

erodeExpression::erodeExpression()
{
	noArguments = 1;
}


erodeExpression::~erodeExpression()
{
}

Variable erodeExpression::evaluate()
{
	Mask* mask = ImageStore::get()->mask.get();
	Mask* newMask = new Mask(mask->width, mask->height);
	Kernel* k = arguments[0]->getResult().get<Kernel>();
	int ks = k->getSize();

	for (int cx = 0; cx < mask->width; cx++)
		for (int cy = 0; cy < mask->height; cy++)
		{
			float min = numeric_limits<float>::max();
			for (int kx = 0; kx <= ks; kx++)
				for (int ky = 0; ky <= ks; ky++)
				{
					float v = mask->getValue(cx + kx - ks / 2, cy + ky - ks / 2) - k->get(kx, ky);
					if (v < min)
						min = v;
				}
			newMask->setValue(cx, cy, min);
		}

	//potential memory leak
	ImageStore::get()->mask.reset(newMask);
	return Variable();
}
