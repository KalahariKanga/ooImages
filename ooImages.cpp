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

	ImageStore store;
	std::string filename;
	if (argc > 1)
		filename = argv[1];
	else
	{
		std::cout << ">>";
		std::getline(std::cin, filename);
	}

	
	store.loadImage(filename);

	Selection selection(store.image->getWidth(), store.image->getHeight());
	Interpreter interpreter;
	interpreter.selection = &selection; 
	interpreter.store = &store;

	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 800 * ((float)store.image->getHeight() / store.image->getWidth())), "Image");
	sf::Texture texture;
	sf::Sprite sprite;

	if (argc > 2)
	{
		std::ifstream file(argv[2]);
		std::string line;
		while (std::getline(file, line))
		{
			texture.loadFromImage(*(store.image->getImage()));
			sprite.setTexture(texture);
			window.draw(sprite);
			window.display();
			std::cout << ">";
			interpreter.interpret(line);

			std::cout << line << std::endl;
		}
		file.close();
		
	}






	std::string input;
	while (1)
	{
		texture.loadFromImage(*(store.image->getImage()));
		sprite.setTexture(texture);
		window.draw(sprite);
		window.display();
		std::cout << ">";
		std::getline(std::cin,input);
		interpreter.interpret(input);
	}

	return 0;
}

