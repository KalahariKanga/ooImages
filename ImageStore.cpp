#include "ImageStore.h"
#include "Selection.h"
ImageStore* ImageStore::instance = nullptr;

ImageStore::ImageStore()
{
}


ImageStore::~ImageStore()
{
}

void ImageStore::loadImage(std::string fname)
{
	image = std::make_shared<ImageObject>();
	image.get()->loadImage(fname);
}

void ImageStore::initialize(std::string fname)
{
	try
	{
		loadImage(fname);
		mask = std::make_shared<Selection>(image->getWidth(), image->getHeight());
	}
	catch (Exception* e)
	{
		std::cout << e->getErrorString();
		delete e;
		abort();
	}
}

ImageStore* ImageStore::get()
{
	if (!instance)
		instance = new ImageStore();
	return instance;
}

ImageObject* ImageStore::getImage()
{
	return image.get();
}