#include "ImageObject.h"


ImageObject::ImageObject(void)
{
	width = height = -1;
	data = nullptr;
}

ImageObject::ImageObject(int width, int height) : width(width), height(height)
{
	data = new sf::Uint8[width * height * 4];
}

ImageObject::~ImageObject(void)
{
	delete data;
}

void ImageObject::colourToData(int x, int y, Colour c)
{
	data[4 * (y*width + x)] = c.r();
	data[4 * (y*width + x) + 1] = c.g();
	data[4 * (y*width + x) + 2] = c.b();
	//data[4 * (y*width + x) + 3] = c.a();
	//TODO: not using alpha channel - could save room removing it?
}

Colour ImageObject::getPixel(float x, float y, bool wrap)
{
	if (wrap)
	{
		while (x > width - 1)
			x -= width;
		while (y > height - 1)
			y -= height;
		while (x < 0)
			x += width;
		while (y < 0)
			y += height;
	}
	else
	{
		if (x < 0)
			x = 0;
		if (y < 0)
			y = 0;
		if (x > width - 1)
			x = width - 1;
		if (y > height - 1)
			y = height - 1;
	}

	Colour tl, tr, bl, br;
	tl = getDataPoint(floor(x), floor(y));
	tr = getDataPoint(ceil(x), floor(y));
	bl = getDataPoint(floor(x), ceil(y));
	br = getDataPoint(ceil(x), ceil(y));

	float xf = x - floor(x);
	float yf = y - floor(y);

	float r = bilint(tl.r(), tr.r(), bl.r(), br.r(), xf, yf);
	float g = bilint(tl.g(), tr.g(), bl.g(), br.g(), xf, yf);
	float b = bilint(tl.b(), tr.b(), bl.b(), br.b(), xf, yf);

	return Colour(r, g, b);
}
Colour ImageObject::getPixel(int x, int y, bool wrap)
{
	if (wrap)
	{
		while (x > width - 1)
			x -= width;
		while (y > height - 1)
			y -= height;
		while (x < 0)
			x += width;
		while (y < 0)
			y += height;
	}
	else
	{
		if (x < 0)
			x = 0;
		if (y < 0)
			y = 0;
		if (x > width - 1)
			x = width - 1;
		if (y > height - 1)
			y = height - 1;
	}
	
	return getDataPoint(x, y);
}

Colour ImageObject::getDataPoint(int x, int y)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return Colour(0, 0, 0); //TODO: wrap or extend or something
	int pos = 4 * (y*width + x);
	return Colour(data[pos], data[pos + 1], data[pos + 2]);// , data[pos + 3]);

}

void ImageObject::setPixel(int x, int y, Colour c)
{
	if (x >= 0 && x < width)
		if (y >= 0 && y < height)
			colourToData(x, y, c);
}

void ImageObject::loadImage(std::string fname)
{
	sf::Image image;
	image.loadFromFile(fname);
	width = image.getSize().x;
	height = image.getSize().y;
	delete data;
	data = new sf::Uint8[width * height * 4];
	const sf::Uint8* pixel = image.getPixelsPtr();
	for (int c = 0; c < width * height * 4; c++)
		data[c] = pixel[c];
}

int ImageObject::getHeight()
{
	return height;
}

int ImageObject::getWidth()
{
	return width;
}

sf::Uint8* ImageObject::getData()
{
	return data;
}