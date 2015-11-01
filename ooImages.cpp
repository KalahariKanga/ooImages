// ooImages.cpp : Defines the entry point for the console application.
//
#include <sstream>
#include "stdafx.h"
#include "ImageObject.h"
#include "ImageStore.h"
#include "Parser.h"

int main(int argc, _TCHAR* argv[])
{
	
	ImageStore* store = ImageStore::get();
	VariableStore* vs = VariableStore::get();
	std::string filename;
	Parser p;

	if (argc == 2) //1 argument - image file
	{
		filename = argv[1];
		store->loadImage(filename);
		store->mask = make_shared<Selection>(store->image->getWidth(), store->image->getHeight());
	}
	else if (argc > 2) //2+ arguments - script file and (several) image files
	{
		std::ifstream file(argv[1]);
		std::stringstream buffer;
		buffer << file.rdbuf();

		for (int c = 2; c < argc; c++)
		{
			ImageObject* image = new ImageObject();
			image->loadImage(argv[c]);
			Variable var(Variable::Type::Image);
			var.set<ImageObject>(image);
			vs->setVariable(std::to_string(c - 2) + "argv", var);
			if (c == 2)
				store->image = std::static_pointer_cast<ImageObject>(var.data);
		}

		store->mask = make_shared<Selection>(store->image->getWidth(), store->image->getHeight());

		try
		{
			p.run(buffer.str());
		}
		catch (Exception* e)
		{
			std::cout << e->getErrorString();
			delete e;
		}

	}
	else //otherwise load from inputted filename
	{
		std::cout << ">>";
		std::getline(std::cin, filename);
		store->loadImage(filename);
	}

	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Image image;
	window.create(sf::VideoMode(800, 800 * ((float)store->image->getHeight() / store->image->getWidth())), "Image");
	
	std::string input;
	while (1)
	{
		image.create(store->image->getWidth(), store->image->getHeight(), store->image->getData());		
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setScale((float)800 / store->image->getWidth(), (float)800 / store->image->getWidth());
		window.setSize(sf::Vector2u(800, 800 * ((float)store->image->getHeight() / store->image->getWidth())));
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

