#pragma once
#include "stdafx.h"
#include "ImageObject.h"
class ImageStore
{
public:
	ImageStore();
	~ImageStore();
	ImageObject* image; //in future, will be an array
	void loadImage(std::string fname);
	void saveImage(std::string fname);
};

