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
	
	setLocalVariable("r", &r);
	setLocalVariable("g", &g);
	setLocalVariable("b", &b);
	setLocalVariable("h", &h);
	setLocalVariable("s", &s);
	setLocalVariable("v", &v);
	setLocalVariable("x", &x);
	setLocalVariable("y", &y);

	for (int cx = 0; cx < image->getWidth(); cx++)
		for (int cy = 0; cy < image->getHeight(); cy++)
		{
			Colour p = image->getPixel(cx, cy);
			x = (float)cx;
			y = (float)cy;
			
			if (store->mask->getValue(cx, cy) > 0)
			{
				h = p.h();
				s = p.s();
				v = p.v();
				r = p.r();
				g = p.g();
				b = p.b();
				float kr, kg, kb;
				kr = kg = kb = 0;
				Variable v = arguments.back()->getResult();
				Kernel* k = v.get<Kernel>();
				int size = k->getSize();
				for (int kx = 0; kx < size; kx++)
					for (int ky = 0; ky < size; ky++)
					{
						Colour q = image->getPixel((int)cx + kx - size / 2, (int)cy + ky - size / 2);
						kr += k->get(kx, ky)*q.r();
						kg += k->get(kx, ky)*q.g();
						kb += k->get(kx, ky)*q.b();
					}
				p.r(clamp<int>((int)kr, 0, 255));
				p.g(clamp<int>((int)kg, 0, 255));
				p.b(clamp<int>((int)kb, 0, 255));
				
			}
			
			buffer->setPixel(cx, cy, p);
		}



	commitBuffer();
	return Variable(Variable::Type::Void);
}