#include "ImageObject.h"


ImageObject::ImageObject(void)
{
	width = height = -1;
}
ImageObject::ImageObject(int width, int height)
{
	this->width = width;
	this->height = height;
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

	x = clamp<float>(x, 0.0f, width - 1);
	y = clamp<float>(y, 0.0f, height - 1);
	Colour tl, tr, bl, br;
	tl = getDataPoint(floor(x), floor(y));
	tr = getDataPoint(ceil(x), floor(y));
	bl = getDataPoint(floor(x), ceil(y));
	br = getDataPoint(ceil(x), ceil(y));

	float xf = x - floor(x);
	float yf = y - floor(y);

	float rt = tl.r() + xf*(tr.r() - tl.r());
	float rb = bl.r() + xf*(br.r() - bl.r());
	float r = rt + yf*(rb - rt);

	float gt = tl.g() + xf*(tr.g() - tl.g());
	float gb = bl.g() + xf*(br.g() - bl.g());
	float g = gt + yf*(gb - gt);

	float bt = tl.b() + xf*(tr.b() - tl.b());
	float bb = bl.b() + xf*(br.b() - bl.b());
	float b = bt + yf*(bb - bt);

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
	//sf::Color c = image.getPixel(x, y);
	
	return getDataPoint(x, y);
}

Colour ImageObject::getDataPoint(int x, int y)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return Colour(0, 0, 0); //TODO: wrap or extend or something
	return Colour(data[4 * (y*width + x)], data[4 * (y*width + x) + 1], data[4 * (y*width + x) + 2]);// , data[4 * (y*width + x) + 3]);

}

void ImageObject::setPixel(int x, int y, Colour c)
{
	if (x >= 0 && x < width)
		if (y >= 0 && y < height)
			colourToData(x, y, c);
			//image.setPixel(x, y, c.getCol());
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