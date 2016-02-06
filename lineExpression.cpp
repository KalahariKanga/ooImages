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

	float x1 = *arguments[0]->getResult().get<Real>();
	float y1 = *arguments[1]->getResult().get<Real>();
	float x2 = *arguments[2]->getResult().get<Real>();
	float y2 = *arguments[3]->getResult().get<Real>();

	Variable var(Variable::Type::Mask);
	Mask* s = new Mask(image->getWidth(), image->getHeight());
	float minX = std::min(x1, x2);
	float maxX = std::max(x1, x2);
	float minY = std::min(y1, y2);
	float maxY = std::max(y1, y2);

	int dx = x2 - x1;
	int dy = y2 - y1;
	int dx1 = std::abs(dx);
	int dy1 = std::abs(dy);
	int px = 2 * dy1 - dx1;
	int py = 2 * dx1 - dy1;
	int x, y, xe, ye;

	for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
			s->setValue(cx, cy, 0);

	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1;
			y = y1;
			xe = x2;
		}
		else
		{
			x = x2;
			y = y2;
			xe = x1;
		}
		s->setValue(x, y, 1);
		for (int i = 0; x < xe; i++)
		{
			x = x + 1;
			if (px < 0)
			{
				px = px + 2 * dy1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx>0 && dy>0))
				{
					y = y + 1;
				}
				else
				{
					y = y - 1;
				}
				px = px + 2 * (dy1 - dx1);
			}
			s->setValue(x, y, 1);
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1;
			y = y1;
			ye = y2;
		}
		else
		{
			x = x2;
			y = y2;
			ye = y1;
		}
		s->setValue(x, y, 1);
		for (int i = 0; y < ye; i++)
		{
			y = y + 1;
			if (py <= 0)
			{
				py = py + 2 * dx1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx>0 && dy>0))
				{
					x = x + 1;
				}
				else
				{
					x = x - 1;
				}
				py = py + 2 * (dx1 - dy1);
			}
			s->setValue(x, y, 1);
		}
	}
	var.set<Mask>(s);
	return var;

}
