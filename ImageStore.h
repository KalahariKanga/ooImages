#pragma once
#include "stdafx.h"
#include "ImageObject.h"
#include "AbstractMask.h"
class ImageStore
{
	static ImageStore* instance;
	std::vector<ImageObject> history;
public:
	ImageStore();
	~ImageStore();
	std::shared_ptr<ImageObject> image;
	std::shared_ptr<AbstractMask> mask;
	ImageObject* getImage();
	void loadImage(std::string fname);
	void initialize(std::string fname);
	static ImageStore* get();
};

