#include "Selection.h"

using namespace std;
Selection::Selection(int width, int height)
{
	this->width = width;
	this->height = height;
	data = new bool*[width];
	for (int c = 0; c < width; c++)
		data[c] = new bool[height];
	toRectangle("0", "0", to_string(width), to_string(height));
}


Selection::~Selection()
{
	//TODO: maybe delete?
}

bool Selection::isInCircle(int x, int y, int cx, int cy, int cr)
{
	if ((x - cx)*(x - cx) + (y - cy)*(y - cy) <= cr*cr)
		return true;
	return false;
}
bool Selection::isInRectangle(int x, int y, int x1, int y1, int x2, int y2)
{
	if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
		return true;
	return false;
}
bool Selection::isInEllipse(int x, int y, int x1, int y1, int x2, int y2)
{
	float cx = (x1 + x2) / 2;
	float cy = (y1 + y2) / 2;
	float a = (x2 - x1) / 2;
	float b = (y2 - y1) / 2;

	if ((x - cx)*(x - cx) / (a*a) + (y - cy)*(y - cy) / (b*b) <= 1)
		return true;
	return false;
}
bool Selection::isInRegion(ImageObject *i, int x, int y, std::string expr)
{
	double tx, ty, r, g, b, h, s, v;

	static std::string current = " ";
	static bool** newselection;


	if (current != expr)
	{
		newselection = new bool*[i->getWidth()];
		for (int c = 0; c < i->getWidth(); ++c)
			newselection[c] = new bool[i->getHeight()];

		current = expr;
		ExpressionParser parser;
		parser.setString(expr);
		parser.addLocalVariable("x", &tx);
		parser.addLocalVariable("y", &ty);
		parser.addLocalVariable("r", &r);
		parser.addLocalVariable("g", &g);
		parser.addLocalVariable("b", &b);
		parser.addLocalVariable("h", &h);
		parser.addLocalVariable("s", &s);
		parser.addLocalVariable("v", &v);
		Colour p;
		for (tx = 0; tx < i->getWidth(); tx += 1)
			for (ty = 0; ty < i->getHeight(); ty += 1)
			{
				p = i->getPixel((int)tx, (int)ty);
				r = p.r();
				g = p.g();
				b = p.b();
				h = p.h();
				s = p.s();
				v = p.v();
				newselection[(int)tx][(int)ty] = parser.evaluate();
			}
	}
	return newselection[x][y];
}

bool Selection::getValue(int x, int y)
{
	while (x < 0)
		x += width;
	while (x >= width)
		x -= width;
	while (y < 0)
		y += width;
	while (y >= width)
		y -= width;
	return data[x][y];
}
void Selection::setValue(int x, int y, bool v)
{
	while (x < 0)
		x += width;
	while (x >= width)
		x -= width;
	while (y < 0)
		y += width;
	while (y >= width)
		y -= width;
	data[x][y] = v;
}

void Selection::toCircle(string cx, string cy, string cr)
{
	ExpressionParser parser[3];
	parser[0].setString(cx);
	parser[1].setString(cy);
	parser[2].setString(cr);

	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			setValue(x, y, isInCircle(x, y, parser[0].evaluate(), parser[1].evaluate(), parser[2].evaluate()));
}
void Selection::toRectangle(string x1, string y1, string x2, string y2)
{
	ExpressionParser parser[4];
	parser[0].setString(x1);
	parser[1].setString(y1);
	parser[2].setString(x2);
	parser[3].setString(y2);
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			setValue(x, y, isInRectangle(x, y, parser[0].evaluate(), parser[1].evaluate(), parser[2].evaluate(), parser[3].evaluate()));

}
void Selection::toEllipse(string x1, string y1, string x2, string y2)
{
	ExpressionParser parser[4];
	parser[0].setString(x1);
	parser[1].setString(y1);
	parser[2].setString(x2);
	parser[3].setString(y2);
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			setValue(x, y, isInEllipse(x, y, parser[0].evaluate(), parser[1].evaluate(), parser[2].evaluate(), parser[3].evaluate()));
}
void Selection::toRegion(ImageObject *i, std::string expr)
{
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			setValue(x, y, isInRegion(i, x, y, expr));
}

void Selection::invert()
{
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			setValue(x, y, getValue(x, y) ? 0 : 1);
}

Selection Selection::combine(string op, Selection* other)
{
	bool(*func)(bool, bool);
	if (op == "and")
		func = &and;
	if (op == "or")
		func = &or;
	if (op == "xor")
		func = &xor;
	if (op == "nand")
		func = &nand;

	Selection newSelection(width, height);
	if (other->width == width && other->height == height)
	{
		
		for (int x = 0; x < width; x++)
			for (int y = 0; y < height; y++)
			{
				bool a = getValue(x, y);
				bool b = other->getValue(x, y);
				newSelection.setValue(x, y, func(a,b));
			}

	}
	else
		return Selection(0, 0);
	return newSelection;
}

Selection Selection::dilate(Selection* kernel, int originx, int originy)
{
	Selection newSelection(width, height);
	newSelection.invert();
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
		{
			
			if (getValue(x, y))
			{
				newSelection.setValue(x, y, 1);
				for (int kx = 0; kx < kernel->width; kx++)
					for (int ky = 0; ky < kernel->height; ky++)
					{
						if (kernel->getValue(kx, ky))
							newSelection.setValue(x + kx - originx, y + ky - originy, 1);
					}
			}
		}
	
	return newSelection;
}

Selection Selection::erode(Selection* kernel, int originx, int originy)
{
	Selection newSelection(width, height);
	newSelection.invert();//selections are true by default
	for (int x = 0; x < width - kernel->width; x++)
		for (int y = 0; y < height - kernel->height; y++)
		{
			bool contained = 1;
			for (int c = 0; c < kernel->width*kernel->height; c++)
			{
				bool source = kernel->getValue(c%kernel->width, c / kernel->width);
				bool target = getValue(x + c%kernel->width, y + c / kernel->width);
				if (source&&!target)
					contained = 0;
			}
			if (contained)
				newSelection.setValue(x + originx, y + originy, 1);
		}
	return newSelection;
}

Selection Selection::create(vector<string> tokens, ImageObject* image)
{
	Selection newSelection(image->getWidth(), image->getHeight());
	if (tokens.front() == "circle")
	{
		newSelection.toCircle(tokens[1], tokens[2], tokens[3]);
	}
	if (tokens.front() == "rectangle")
	{
		newSelection.toRectangle(tokens[1], tokens[2], tokens[3], tokens[4]);
	}
	if (tokens.front() == "ellipse")
	{
		newSelection.toEllipse(tokens[1], tokens[2], tokens[3], tokens[4]);
	}
	if (tokens.front() == "region")
	{
		newSelection.toRegion(image, tokens[1]);
	}
	return newSelection;
}

Selection Selection::create(vector<string> tokens, int width, int height)
{
	Selection newSelection(width, height);
	if (tokens.front() == "circle")
	{
		newSelection.toCircle(tokens[1], tokens[2], tokens[3]);
	}
	if (tokens.front() == "rectangle")
	{
		newSelection.toRectangle(tokens[1], tokens[2], tokens[3], tokens[4]);
	}
	if (tokens.front() == "ellipse")
	{
		newSelection.toEllipse(tokens[1], tokens[2], tokens[3], tokens[4]);
	}
	if (tokens.front() == "region")
	{
		std::cout << "Can't have regions as structuring elements yet\n";
	}
	return newSelection;
}

Selection Selection::createStructuringElement(vector<string> tokens)
{
	
}