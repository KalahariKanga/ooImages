#pragma once
#include "stdafx.h"
#include "ImageObject.h"
class ImageStore
{
	std::vector<ImageObject> history;
	int histPos;
public:
	ImageStore();
	~ImageStore();
	ImageObject* image; //in future, will be an array
	void loadImage(std::string fname);
	void saveImage(std::string fname);
	void addUndoPoint();
	void undo();
	void redo();
};

