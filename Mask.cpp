#include "Mask.h"

RESOURCE_DEFINE_STATIC_PROPERTY_MAP(Mask)

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

Mask::Mask(const Mask& obj)
{
	width = obj.width;
	height = obj.height;
	data = new float*[width];
	for (int c = 0; c < width; c++)
		data[c] = new float[height];
	for (int cx = 0; cx < width; cx++)
		for (int cy = 0; cy < height; cy++)
			data[cx][cy] = obj.data[cx][cy];
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
	if (x < 0 || x > width || y < 0 || y > height)
		return;
	data[x][y] = v;
}

void Mask::resize(int w, int h)
{
	float** newData = new float*[w];
	for (int c = 0; c < w; c++)
		newData[c] = new float[h];
	for (int cx = 0; cx < w; cx++)
		for (int cy = 0; cy < h; cy++)
		{
			if (cx < width && cy < height)
				newData[cx][cy] = data[cx][cy];
			else
				newData[cx][cy] = 1;
		}

	for (int c = 0; c < width; c++)
		delete[] data[c];
	delete[] data;

	data = newData;

	width = w;
	height = h;
}

void Mask::invert()
{
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
		{
			data[x][y] = 1 - data[x][y];
		}
}

void Mask::about()
{
	std::cout << "About\n";
	std::cout << "Mask\n";
	std::cout << "Width: " << width << " Height: " << height << "\n";
	std::cout << "Sample: ";
	for (int cy = 0; cy < std::min(10, height); cy++)
	{
		std::cout << std::endl;
		for (int cx = 0; cx < std::min(width, 10); cx++)
			std::cout << getValue(cx, cy) << " ";
	}
	std::cout << "\n";

}

void Mask::loadProperties()
{
	setProperty("width", [](Mask* m){return m->width; });
	setProperty("height", [](Mask* m){return m->height; });
}