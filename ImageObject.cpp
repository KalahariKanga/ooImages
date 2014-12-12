#include "ImageObject.h"


ImageObject::ImageObject(void)
{
	width = height = -1;
}
ImageObject::ImageObject(int width, int height)
{
	image.create(width, height);
}


ImageObject::~ImageObject(void)
{
}

Colour ImageObject::getPixel(float x, float y, bool wrap)
{
	if (wrap)
	{
		while (x > image.getSize().x - 1)
			x -= image.getSize().x;
		while (y > image.getSize().y - 1)
			y -= image.getSize().y;
		while (x < 0)
			x += image.getSize().x;
		while (y < 0)
			y += image.getSize().y;
	}
	else
	{
		if (x < 0)
			x = 0;
		if (y < 0)
			y = 0;
		if (x > image.getSize().x - 1)
			x = image.getSize().x - 1;
		if (y > image.getSize().y - 1)
			y = image.getSize().y - 1;
	}

	x = clamp<float>(x, 0.0f, image.getSize().x - 1);
	y = clamp<float>(y, 0.0f, image.getSize().y - 1);
	sf::Color tl, tr, bl, br;
	tl = image.getPixel(floor(x), floor(y));
	tr = image.getPixel(ceil(x), floor(y));
	bl = image.getPixel(floor(x), ceil(y));
	br = image.getPixel(ceil(x), ceil(y));

	float xf = x - floor(x);
	float yf = y - floor(y);

	float rt = tl.r + xf*(tr.r - tl.r);
	float rb = bl.r + xf*(br.r - bl.r);
	float r = rt + yf*(rb - rt);

	float gt = tl.g + xf*(tr.g - tl.g);
	float gb = bl.g + xf*(br.g - bl.g);
	float g = gt + yf*(gb - gt);

	float bt = tl.b + xf*(tr.b - tl.b);
	float bb = bl.b + xf*(br.b - bl.b);
	float b = bt + yf*(bb - bt);

	return Colour(r, g, b);
}
Colour ImageObject::getPixel(int x, int y, bool wrap)
{
	if (wrap)
	{
		while (x > image.getSize().x - 1)
			x -= image.getSize().x;
		while (y > image.getSize().y - 1)
			y -= image.getSize().y;
		while (x < 0)
			x += image.getSize().x;
		while (y < 0)
			y += image.getSize().y;
	}
	else
	{
		if (x < 0)
			x = 0;
		if (y < 0)
			y = 0;
		if (x > image.getSize().x - 1)
			x = image.getSize().x - 1;
		if (y > image.getSize().y - 1)
			y = image.getSize().y - 1;
	}
	sf::Color c = image.getPixel(x, y);
	return Colour(c.r, c.g, c.b);
}
void ImageObject::setPixel(int x, int y, Colour c)
{
	if (x >= 0 && x < image.getSize().x)
		if (y >= 0 && y < image.getSize().y)
			image.setPixel(x, y, c.getCol());
}

void ImageObject::loadImage(std::string fname)
{
	image.loadFromFile(fname);
	width = image.getSize().x;
	height = image.getSize().y;
}

int ImageObject::getHeight()
{
	return height;
}

int ImageObject::getWidth()
{
	return width;
}

sf::Image* ImageObject::getImage()
{
	return &image;
}