#include "minExpression.h"


minExpression::minExpression()
{
	noArguments = 1;
}


minExpression::~minExpression()
{
}

Variable minExpression::evaluate()
{
	ImageStore* store = ImageStore::get();
	ImageObject* image = store->getImage();	

	float min = std::numeric_limits<float>::max();

	for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
		{
			if (store->mask->getValue(cx, cy) > 0)
			{
				Colour p = image->getPixel(cx, cy);
				setLocalVariable("x", cx);
				setLocalVariable("y", cy);
				setLocalVariable("h", p.h());
				setLocalVariable("s", p.s());
				setLocalVariable("v", p.v());
				setLocalVariable("r", p.r());
				setLocalVariable("g", p.g());
				setLocalVariable("b", p.b());
				Variable var = arguments.back()->getResult();
				if (*var.get<float>() < min)
					min = *var.get<float>();
			}
		}
	Variable var(Variable::Type::Real);
	var.set<float>(new float(min));
	return var;
}