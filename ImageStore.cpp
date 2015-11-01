#include "ImageStore.h"

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

void ImageStore::saveImage(std::string fname)
{
	std::cout << "Not implemented";
	//image->getImage()->saveToFile(fname);
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