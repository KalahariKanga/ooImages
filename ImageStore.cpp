#include "ImageStore.h"


ImageStore::ImageStore()
{
}


ImageStore::~ImageStore()
{
}

void ImageStore::loadImage(std::string fname)
{
	image = new ImageObject();
	image->loadImage(fname);
}

void saveImage(std::string fname)
{
	//TODO:this function
}