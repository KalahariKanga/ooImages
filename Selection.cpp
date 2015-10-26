#include "Selection.h"

using namespace std;
Selection::Selection(int width, int height)
{
	this->width = width;
	this->height = height;
	data = new bool*[width];
	for (int c = 0; c < width; c++)
		data[c] = new bool[height];

	for (int cx = 0; cx < width; cx++)
		for (int cy = 0; cy < height; cy++)
			setValue(cx, cy, 1);
}

Selection::Selection(Mask& mask, float boundary = 0)
{
	width = mask.width;
	height = mask.height;
	data = new bool*[width];
	for (int c = 0; c < width; c++)
		data[c] = new bool[height];

	for (int cx = 0; cx < width; cx++)
		for (int cy = 0; cy < height; cy++)
		{
			if (mask.getValue(cx, cy) > boundary)
				setValue(cx, cy, 1);
			else
				setValue(cx, cy, 0);
		}
	setProperty("width", &width);
	setProperty("height", &height);
}

Selection::~Selection()
{
	for (int c = 0; c < width; c++)
		delete[] data[c];
	delete[] data;
}

float Selection::getValue(int x, int y)
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

void Selection::invert()
{
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			setValue(x, y, getValue(x, y) ? 0 : 1);
}

void Selection::dilate(Selection* kernel)
{
	int originx = kernel->width / 2;
	int originy = kernel->height / 2;
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
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			setValue(x, y, newSelection.getValue(x, y));
	
}

void Selection::erode(Selection* kernel)
{
	int originx = kernel->width / 2;
	int originy = kernel->height / 2;

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
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			setValue(x, y, newSelection.getValue(x, y));

}