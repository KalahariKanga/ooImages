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
	
	if (histPos < history.size()-1)
	{	
		history.resize(histPos+1);
	}
	history.push_back((*image));
	histPos++;
}

void ImageStore::undo()
{
	if (histPos > 0)
	{
		histPos--;
		image = &(history[histPos]);
	}
	std::cout << "HistPos " << histPos << " history size " << history.size() << std::endl;
}

void ImageStore::redo()
{
	if (histPos < history.size()-1)
	{
		histPos++;
		image = &(history[histPos]);
	}
	std::cout << "HistPos " << histPos << " history size " << history.size() << std::endl;
}