#include "AbstractMask.h"


AbstractMask::AbstractMask()
{
}


AbstractMask::~AbstractMask()
{
}

void AbstractMask::about()
{
	std::cout << "About\n";
	std::cout << "Width: " << width << " Height: " << height << "\n";
	std::cout << "Sample: ";
	for (int cy = 0; cy < std::min(10, height); cy++)
	{
		std::cout << std::endl;
		for (int cx = 0; cx < std::min(width, 10); cx++)
			std::cout << getValue(cx, cy) << " ";
	}

}