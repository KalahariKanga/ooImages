#pragma once
#include "stdafx.h"
#include "ImageObject.h"
#include "AbstractMask.h"
class ImageStore
{
	static ImageStore* instance;
	std::vector<ImageObject> history;
	int histPos;
public:
	ImageStore();
	~ImageStore();
	ImageObject* image;
	AbstractMask* mask;
	void loadImage(std::string fname);
	void saveImage(std::string fname);
	void addUndoPoint();
	void undo();
	void redo();
	static ImageStore* get();
};

