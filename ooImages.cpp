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

	Colour::loadProperties();
	ImageObject::loadProperties();
	Kernel::loadProperties();
	Function::loadProperties();
	Mask::loadProperties();

	Parser p;

	if (argc == 2) //1 argument - image file
	{
		store->initialize(argv[1]);
		vs->setArrayVariable("argv", 0, Variable(store->getImage()));
	}
	else if (argc > 2) //2+ arguments - script file and (several) image files
	{
		std::ifstream file(argv[1]);
		std::stringstream buffer;
		buffer << file.rdbuf();

		store->initialize(argv[2]);
		vs->setArrayVariable("argv", 0, Variable(store->getImage()));

		for (int c = 3; c < argc; c++)
		{
			Variable var(new ImageObject());
			var.get<ImageObject>()->loadImage(argv[c]);
			vs->setArrayVariable("argv", c - 2, var);
		}
		p.run(buffer.str());
	}
	else //otherwise load from inputted filename
	{
		std::string filename;
		std::cout << ">>";
		std::getline(std::cin, filename);
		if (filename == "")
			store->initialize(640, 480);
		else
			store->initialize(filename);
		vs->setArrayVariable("argv", 0, Variable(store->getImage()));
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
			p.run(input);
		}
	});
	
	window.setSize(sf::Vector2u(800, 600));
	sf::View view;
	while (1)
	{
		image.create(store->image->getWidth(), store->image->getHeight(), store->image->getData());		
		texture.loadFromImage(image);
		sprite.setTexture(texture, true);
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
		
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				return 0; //i -think- this is acceptable
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

	return 0;
}

