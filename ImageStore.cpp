#include "ImageStore.h"


ImageStore::ImageStore()
{
	histPos = -1;
}


ImageStore::~ImageStore()
{
}

void ImageStore::loadImage(std::string fname)
{
	image = new ImageObject();
	image->loadImage(fname);
	addUndoPoint();
}

void saveImage(std::string fname)
{
	//TODO:this function
}

void ImageStore::addUndoPoint()
{	
	if (histPos < history.size())
	{	
		history.resize(histPos+1);
	}
	histPos++;
	history.push_back(*image);
}

void ImageStore::undo()
{
	if (histPos > 0)
	{
		histPos--;
		image = new ImageObject(history[histPos]);
	}
}

void ImageStore::redo()
{
	if (histPos < history.size()-1)
	{
		histPos++;
		image = new ImageObject(history[histPos]);
	}
}