#pragma once
#include "stdafx.h"
#include "ImageObject.h"
#include "Mask.h"
class ImageStore
{
	static ImageStore* instance;
public:
	ImageStore();
	~ImageStore();
	std::shared_ptr<ImageObject> image;
	std::shared_ptr<Mask> mask;
	ImageObject* getImage();
	void loadImage(std::string fname);
	void initialize(std::string fname);
	void initialize(int width, int height);
	static ImageStore* get();
};

