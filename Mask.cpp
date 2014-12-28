#include "Mask.h"

Mask::Mask(int width, int height)
{
	this->width = width;
	this->height = height;
	data = new float*[width];
	for (int c = 0; c < width; c++)
		data[c] = new float[height];
	//toRectangle("0", "0", to_string(width), to_string(height));
}


Mask::~Mask()
{
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
void Mask::invert()
{
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			setValue(x, y, 1-getValue(x, y));
}
