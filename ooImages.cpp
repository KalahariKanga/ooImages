// ooImages.cpp : Defines the entry point for the console application.
//
#include <sstream>
#include <thread>
#include "stdafx.h"
#include "ImageObject.h"
#include "ImageStore.h"
#include "Parser.h"

int main(int argc, _TCHAR* argv[])
{
	
	ImageStore* store = ImageStore::get();
	VariableStore* vs = VariableStore::get();
	std::string filename;

	Colour::loadProperties();
	ImageObject::loadProperties();
	Kernel::loadProperties();
	Function::loadProperties();
	Mask::loadProperties();

	Parser p;

	if (argc == 2) //1 argument - image file
	{
		filename = argv[1];
		store->initialize(filename);
		Variable var(store->getImage());
		vs->setArrayVariable("argv", 0, var);
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
			Variable var(image);
			vs->setArrayVariable("argv", c - 2, var);

			if (c == 2)
				store->image = var.getShared<ImageObject>();;
		}

		store->mask = make_shared<Mask>(store->image->getWidth(), store->image->getHeight());

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
		store->initialize(filename);
		Variable var(store->getImage());
		vs->setArrayVariable("argv", 0, var);
	}

	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Image image;
	sf::Event ev; 
	window.create(sf::VideoMode(800, 800 * ((float)store->image->getHeight() / store->image->getWidth())), "Image");
	
	std::thread parserThread([&p]()
	{
		std::string input;
		while (1)
		{
			std::cout << ">";
			std::getline(std::cin, input);
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
	});
	
	window.setSize(sf::Vector2u(800, 600));
	sf::View view;
	while (1)
	{
		image.create(store->image->getWidth(), store->image->getHeight(), store->image->getData());		
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		int imageWidth = image.getSize().x;
		int imageHeight = image.getSize().y;
		int windowWidth = window.getSize().x;
		int windowHeight = window.getSize().y;
		view.setCenter(imageWidth / 2, imageHeight / 2);
		if (imageWidth > imageHeight * ((float)windowWidth / windowHeight))
		{
			view.setSize(imageWidth, imageWidth * ((float)windowHeight / windowWidth));
		}
		else
		{
			view.setSize(imageHeight * ((float)windowWidth / windowHeight), imageHeight);
		}
		window.setView(view);
		window.clear();
		window.draw(sprite);
		window.display();
		
		while (window.pollEvent(ev)){}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

	return 0;
}

