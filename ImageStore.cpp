#include "ImageStore.h"


ImageStore::ImageStore()
{
	histPos = -1;
}


ImageStore::~ImageStore()
{
	delete image;
}

void ImageStore::loadImage(std::string fname)
{
	image = new ImageObject();
	image->loadImage(fname);
	addUndoPoint();
}

void ImageStore::saveImage(std::string fname)
{
	std::cout << "Not implemented";
	//image->getImage()->saveToFile(fname);
}

void ImageStore::addUndoPoint()
{	
	//
	//probably need to use shared pointer
	//
	/*if (histPos < history.size())
	{	
		history.resize(histPos+1);
	}
	histPos++;
	history.push_back(*image);*/
	
}

void ImageStore::undo()
{
	if (histPos > 0)
	{
		histPos--;
		delete image;
		image = new ImageObject(history[histPos]);
	}
}

void ImageStore::redo()
{
	if (histPos < history.size()-1)
	{
		histPos++;
		delete image;
		image = new ImageObject(history[histPos]);
	}
}