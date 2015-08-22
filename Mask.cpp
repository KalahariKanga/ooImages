#include "Mask.h"
Mask::Mask()
{

}
Mask::Mask(int width, int height)
{
	this->width = width;
	this->height = height;
	data = new float*[width];
	for (int c = 0; c < width; c++)
		data[c] = new float[height];
	for (int cx = 0; cx < width; cx++)
		for (int cy = 0; cy < height; cy++)
			setValue(cx, cy, 1);
}
Mask::Mask(vector<string> tokens, ImageObject* image)
{
	this->width = image->getWidth();
	this->height = image->getHeight();
	data = new float*[width];
	for (int c = 0; c < width; c++)
		data[c] = new float[height];
	
	if (tokens.front() == "circle")
	{
		toCircle(tokens[1], tokens[2], tokens[3], tokens[4]);
	}
	if (tokens.front() == "line")
	{
		toLine(tokens[1], tokens[2], tokens[3], tokens[4]);
	}
	if (tokens.front() == "region")
	{
		toRegion(image, tokens[1]);
	}
}

Mask::~Mask()
{
	for (int c = 0; c < width; c++)
		delete[] data[c];
	delete[] data;
}

float Mask::valueInCircle(int x, int y, int cx, int cy, int r1, int r2)
{
	float d = distance(x, y, cx, cy);
	if (d > r2)
		return 0;
	if (d < r1)
		return 1;
	return (r2 - d) / (r2 - r1);
}
float Mask::valueInLine(int x, int y, int x1, int y1, int x2, int y2)
{
	//find scalar projection of (x,y) onto (x2-x1,y2-y1)
	float p = (x - x1)*(x2 - x1) + (y - y1)*(y2 - y1);
	//p /= sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	p /= (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);

	return clamp<float>(p,0,1);
}
float Mask::valueInRegion(ImageObject* i, int x, int y, std::string expr)
{
	//TODO: probs memory leak
	float tx, ty, r, g, b, h, s, v;

	static std::string current = " ";
	static float** newselection;


	if (current != expr)
	{
		newselection = new float*[i->getWidth()];
		for (int c = 0; c < i->getWidth(); ++c)
			newselection[c] = new float[i->getHeight()];

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
				newselection[(int)tx][(int)ty] = clamp<float>(parser.evaluate(), 0, 1);
			}
	}
	return newselection[x][y];
}
float Mask::getValue(int x, int y)
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

void Mask::setValue(int x, int y, float v)
{
	v = clamp<float>(v, 0, 1);
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
void Mask::toCircle(string cx, string cy, string r1, string r2)
{
	ExpressionParser parser[4];
	parser[0].setString(cx);
	parser[1].setString(cy);
	parser[2].setString(r1);
	parser[3].setString(r2);

	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			setValue(x, y, valueInCircle(x, y, parser[0].evaluate(), parser[1].evaluate(), parser[2].evaluate(), parser[3].evaluate()));
}
void Mask::toLine(string x1, string y1, string x2, string y2)
{
	ExpressionParser parser[4];
	parser[0].setString(x1);
	parser[1].setString(y1);
	parser[2].setString(x2);
	parser[3].setString(y2);

	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			setValue(x, y, valueInLine(x, y, parser[0].evaluate(), parser[1].evaluate(), parser[2].evaluate(), parser[3].evaluate()));
}
void Mask::toRegion(ImageObject* i, std::string expr)
{
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			setValue(x, y, valueInRegion(i, x, y, expr));
}
void Mask::invert()
{
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
		{
			float v = clamp<float>(getValue(x, y),0,1);
			setValue(x, y, 1 - v);
		}
}

void Mask::combine(std::string op, AbstractMask* other)
{
	if (other->width == width && other->height == height)
	{

		for (int x = 0; x < width; x++)
			for (int y = 0; y < height; y++)
			{
				float a = getValue(x, y);
				float b = other->getValue(x, y);
				float v = 0;
				if (op == "add")
					v = clamp<float>(a + b, 0, 1);
				if (op == "sub")
					v = clamp<float>(a - b, 0, 1);
				if (op == "max")
					v = clamp<float>(std::max(a, b), 0, 1);
				if (op == "min")
					v = clamp<float>(std::min(a, b), 0, 1);

				setValue(x, y, v);
			}
	}
}