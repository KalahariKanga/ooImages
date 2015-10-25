// ooImages.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ImageObject.h"
#include "ImageModifier.h"
#include "Interpreter.h"
#include "Invert.h"
#include "ImageStore.h"
#include "ScriptManager.h"

#include "Parser.h"

int main(int argc, _TCHAR* argv[])
{
	
	ImageStore* store = ImageStore::get();
	std::string filename;
	if (argc > 1)
		filename = argv[1];
	else
	{
		std::cout << ">>";
		std::getline(std::cin, filename);
	}

	
	store->loadImage(filename);
	store->mask = make_shared<Selection>(store->image->getWidth(), store->image->getHeight());
	Parser p;

	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 800 * ((float)store->image->getHeight() / store->image->getWidth())), "Image");
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Image image;
	
	std::string input;
	while (1)
	{
		image.create(store->image->getWidth(), store->image->getHeight(), store->image->getData());		
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		//sprite.setScale((float)800 / store->image->getWidth(), (float)800 / store->image->getWidth());
		//window.create(sf::VideoMode(800, 800 * ((float)store->image->getHeight() / store->image->getWidth())), "Image");
		window.clear();
		window.draw(sprite);
		window.display();
		std::cout << ">";
		std::getline(std::cin,input);
		try
		{
			p.run(input);
		}
		catch (Exception* e)
		{
			std::cout << e->getErrorString();
			delete e;
		}
	}

	return 0;
}

