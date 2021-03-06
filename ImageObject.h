#pragma once
#include "Colour.h"
#include "core.h"
#include "ResourcePropertyHelper.h"

class ImageObject : public ResourcePropertyHelper<ImageObject>
{
	int width, height;
	sf::Uint8* data = nullptr;
public:
	Colour getDataPoint(int x, int y);
	void colourToData(int x, int y, Colour c);
	Colour getPixel(float x, float y, bool wrap = 0);
	Colour getPixel(int x, int y, bool wrap = 0);
	void setPixel(int x, int y, Colour colour);
	ImageObject(void);
	ImageObject(int width, int height);
	ImageObject(const ImageObject& obj);
	~ImageObject(void);

	void loadImage(std::string fname);
	void saveImage(std::string fname);
	int getHeight();
	int getWidth();
	sf::Uint8* getData();
	virtual void about();

	static void loadProperties();
};

