#include "Mask.h"

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
	//setProperty("width", [width](){return width; });
	//setProperty("height", [height](){return height; });
}

Mask::~Mask()
{
	for (int c = 0; c < width; c++)
		delete[] data[c];
	delete[] data;
}

//keep until there are expressions to make these
/*
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
}*/

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

void Mask::invert()
{
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
		{
			float v = clamp<float>(getValue(x, y),0,1);
			setValue(x, y, 1 - v);
		}
}