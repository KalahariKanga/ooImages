#include "lineExpression.h"
#include "ImageStore.h"

lineExpression::lineExpression()
{
	noArguments = 4;
}


lineExpression::~lineExpression()
{
}

Variable lineExpression::evaluate()
{
	ImageStore* store = ImageStore::get();
	ImageObject* image = store->getImage();

	float x1 = *arguments[0]->getResult().get<float>();
	float y1 = *arguments[1]->getResult().get<float>();
	float x2 = *arguments[2]->getResult().get<float>();
	float y2 = *arguments[3]->getResult().get<float>();

	float minX = std::min(x1, x2);
	float maxX = std::max(x1, x2);
	float minY = std::min(y1, y2);
	float maxY = std::max(y1, y2);

	Variable var(Variable::Type::Mask);
	Mask* s = new Mask(image->getWidth(), image->getHeight());
	
	float d = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
		{
			s->setValue(cx, cy, 0);
			if (cx >= minX && cx <= maxX && cy >= minY && cy <= maxY)
			{
				float d1 = sqrt((cx - x1)*(cx - x1) + (cy - y1)*(cy - y1));
				float d2 = sqrt((cx - x2)*(cx - x2) + (cy - y2)*(cy - y2));
				if (abs(d1 + d2 - d) < 0.0001)//epsilon
					s->setValue(cx, cy, 1);
			}
		}
	var.set<Mask>(s);
	return var;

}
