#include "convolveExpression.h"


convolveExpression::convolveExpression()
{
	noArguments = 1;
}


convolveExpression::~convolveExpression()
{
}

Variable convolveExpression::evaluate()
{
	ImageStore* store = ImageStore::get();
	ImageObject* image = store->getImage();
	float x, y, r, g, b, h, s, v;
	addLocalVariable("x", &x);
	addLocalVariable("y", &y);
	addLocalVariable("h", &h);
	addLocalVariable("s", &s);
	addLocalVariable("v", &v);
	addLocalVariable("r", &r);
	addLocalVariable("g", &g);
	addLocalVariable("b", &b);

	for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
		{
			Colour p = image->getPixel(cx, cy);
			x = cx;
			y = cy;
			
			if (store->mask->getValue(cx, cy) > 0)
			{
				r = p.r();
				g = p.g();
				b = p.b();
				h = p.h();
				s = p.s();
				v = p.v();
				int kr, kg, kb;
				kr = kg = kb = 0;
				Variable v = arguments.back()->getResult();
				Kernel* k = v.get<Kernel>();
				int size = k->getSize();
				for (int kx = 0; kx < size; kx++)
					for (int ky = 0; ky < size; ky++)
					{
						Colour q = image->getPixel((int)x + kx - size / 2, (int)y + ky - size / 2);
						kr += k->get(kx, ky)*q.r();
						kg += k->get(kx, ky)*q.g();
						kb += k->get(kx, ky)*q.b();
					}
				p.r(clamp<int>(kr, 0, 255));
				p.g(clamp<int>(kg, 0, 255));
				p.b(clamp<int>(kb, 0, 255));
				
			}
			
			buffer->setPixel(cx, cy, p);
		}



	commitBuffer();
	return Variable(Variable::Type::Void);
}