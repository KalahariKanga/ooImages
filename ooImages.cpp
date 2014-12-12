// ooImages.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ImageObject.h"
#include "ImageModifier.h"
#include "ExpressionParser.h"
#include "Interpreter.h"
#include "Invert.h"
#include "ImageStore.h"

int main(int argc, _TCHAR* argv[])
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "Window");
	sf::Texture texture;
	sf::Sprite sprite;

	/*ImageObject image;
	image.loadImage("C:\\Users\\David\\Pictures\\test.bmp");
	Selection selection(image.getWidth(),image.getHeight());
	selection.toRegion(&image, "x<y");
	Invert invert(&image, &selection);
	invert.modify();*/


	ImageStore store;
	store.loadImage("C:\\Users\\David\\Pictures\\test.bmp");
	Selection selection(store.image->getWidth(), store.image->getHeight());
	Interpreter interpreter;
	interpreter.selection = &selection; 
	interpreter.store = &store;
	std::string input;
	while (1)
	{
		std::cout << ">>";
		std::getline(std::cin,input);
		interpreter.interpret(input);
		texture.loadFromImage(*(store.image->getImage()));
		sprite.setTexture(texture);
		window.draw(sprite);
		window.display();
	}
	//system("pause");
	return 0;
}

