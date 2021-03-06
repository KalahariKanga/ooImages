#include "ImageObject.h"
#include "Exception.h"

RESOURCE_DEFINE_STATIC_PROPERTY_MAP(ImageObject)


ImageObject::ImageObject(void)
{
	width = height = 0;
	data = nullptr;
}

ImageObject::ImageObject(int width, int height) : width(width), height(height)
{
	data = new sf::Uint8[width * height * 4];
}

ImageObject::ImageObject(const ImageObject& obj)
{
	width = obj.width;
	height = obj.height;
	data = new sf::Uint8[width * height * 4];
	for (int c = 0; c < width * height * 4; c++)
		data[c] = obj.data[c];
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
	data[4 * (y*width + x) + 3] = c.a();
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
	float a = bilint(tl.a(), tr.a(), bl.a(), br.a(), xf, yf);
	return Colour(r, g, b, a);
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
	return Colour(data[pos], data[pos + 1], data[pos + 2], data[pos + 3]);

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
	if (!image.loadFromFile(fname))
		throw new Exception(Exception::ErrorType::FILE_LOAD_ERROR);
	width = image.getSize().x;
	height = image.getSize().y;
	delete data;
	data = new sf::Uint8[width * height * 4];
	const sf::Uint8* pixel = image.getPixelsPtr();
	for (int c = 0; c < width * height * 4; c++)
		data[c] = pixel[c];
}

void ImageObject::saveImage(std::string fname)
{
	sf::Image image;
	image.create(width, height, data);
	if (!image.saveToFile(fname))
		throw new Exception(Exception::ErrorType::FILE_SAVE_ERROR);
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

void ImageObject::about()
{
	std::cout << "About\n";
	std::cout << "Image\n";
	std::cout << "Width: " << width << " Height: " << height << "\n";
}

void ImageObject::loadProperties()
{
	setProperty("width", [](ImageObject* i){return i->getWidth(); });
	setProperty("height", [](ImageObject* i){return i->getHeight(); });
}