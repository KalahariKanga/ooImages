#include "regionExpression.h"


regionExpression::regionExpression()
{
	noArguments = 1;
}


regionExpression::~regionExpression()
{
}

Variable regionExpression::evaluate()
{
	
	ImageStore* store = ImageStore::get();
	ImageObject* image = store->getImage();
	Mask* mask = new Mask(image->getWidth(), image->getHeight());
	
	for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
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

				float val = *arguments.back()->getResult().get<float>();
				mask->setValue(cx, cy, val);
				
		}
	Variable var(Variable::Type::Mask);
	var.set<Mask>(mask);
	return var;
}
