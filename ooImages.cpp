// ooImages.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ImageObject.h"
#include "ImageModifier.h"
#include "ExpressionParser.h"
#include "Interpreter.h"
#include "Invert.h"
#include "ImageStore.h"
#include "ScriptManager.h"

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

	Mask mask(store.image->getWidth(), store.image->getHeight());
	Interpreter interpreter;
	interpreter.mask = &mask;
	interpreter.store = &store;

	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 800 * ((float)store.image->getHeight() / store.image->getWidth())), "Image");
	sf::Texture texture;
	sf::Sprite sprite;
	ExpressionParser::updateVariable("image_width", std::to_string(store.image->getWidth()));
	ExpressionParser::updateVariable("image_height", std::to_string(store.image->getHeight()));
	if (argc > 2)
	{
		std::ifstream file(argv[2]);
		ScriptManager scriptmanager;
		scriptmanager.interpreter = &interpreter;
		scriptmanager.loadScript(&file);
		
	}


	std::string input;
	while (1)
	{
		texture.loadFromImage(*(store.image->getImage()));
		sprite.setTexture(texture);
		sprite.setScale((float)800 / store.image->getWidth(), (float)800 / store.image->getWidth());
		window.draw(sprite);
		window.display();
		std::cout << ">";
		std::getline(std::cin,input);
		interpreter.interpret(input);
	}

	return 0;
}

