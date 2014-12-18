#include "Interpreter.h"
#include "ExpressionParser.h"
#include "Invert.h"
#include "RgbTransform.h"
#include "HsvTransform.h"
#include "Convolve.h"
#include "Transform.h"
Interpreter::Interpreter()
{
}


Interpreter::~Interpreter()
{
}

std::vector<std::string> Interpreter::tokenizeString(std::string string)
{
	std::stringstream stream;
	std::string token;
	std::vector<std::string> list;
	stream << string;
	while (std::getline(stream, token,' '))
	{
		//TODO:trim tokens for leading and trailing spaces
		list.push_back(token);
	}
	return list;
}

void Interpreter::interpret(std::string command)
{
	std::vector<std::string> tokens;
	tokens = tokenizeString(command);
	std::string function = tokens.front();
	tokens.erase(tokens.begin());

	if (function == "var")
	{
		//DONE: dont assume the correct number of tokens
		if (tokens.size() == 2)
			ExpressionParser::updateVariable(tokens.front(), tokens.back());
		else
			std::cout << "Incorrect number of arguments, 2 expected\n";
	}

	if (function == "expr")
	{
		if (tokens.size() == 2)
			ExpressionParser::updateExpression(tokens.front(), tokens.back());
		else
			std::cout << "Incorrect number of arguments, 2 expected\n";
	}

	if (function == "eval")
	{
		if (tokens.size() == 1)
		{
			ExpressionParser parser;
			parser.setString(tokens.front());
			std::cout << tokens.front() << ": " << parser.evaluate() << std::endl;
		}
		else
			std::cout << "Incorrect number of arguments, 1, expected\n";
	}

	if (function == "select")
	{
		*selection = Selection::create(tokens, store->image);
	}

	if (function == "selection")
	{
		std::string op = tokens.front();
		tokens.erase(tokens.begin());
		if (op == "dilate")
			*selection = selection->dilate(&Selection::createStructuringElement(tokens));
		else if (op == "erode")
			*selection = selection->erode(&Selection::createStructuringElement(tokens));
		else if (op == "invert")
			selection->invert();
		else
			*selection = selection->combine(op, &Selection::create(tokens, store->image));
	}

	if (function == "undo")
	{
		store->undo();
	}
	if (function == "redo")
	{
		store->redo();
	}
	if (function == "save")
	{
		store->saveImage(tokens.front());
	}

	if (function == "invert")
	{
		Invert invert(store->image, selection);
		invert.modify();
		store->addUndoPoint();
	}
	if (function == "rgb")
	{
		if (tokens.size() <= 3 && tokens.size() > 0)
		{
			RgbTransform rgb(store->image, selection);
			rgb.expr[0] = "r";
			rgb.expr[1] = "g";
			rgb.expr[2] = "b";
			
			for (int c = 0; c < tokens.size(); c++)
				rgb.expr[c] = tokens[c];

			rgb.modify();
			store->addUndoPoint();
		}
	}
	if (function == "hsv")
	{
		if (tokens.size() <= 3 && tokens.size() > 0)
		{
			HsvTransform hsv(store->image, selection);
			hsv.expr[0] = "r";
			hsv.expr[1] = "g";
			hsv.expr[2] = "b";

			for (int c = 0; c < tokens.size(); c++)
				hsv.expr[c] = tokens[c];

			hsv.modify();
			store->addUndoPoint();
		}
	}
	if (function == "convolve")
	{
		if (tokens.size() <= 9 && tokens.size() > 0)
		{
			Convolve convolve(store->image, selection);
			for (int c = 0; c < 9; c++)
				convolve.expr[c] = "0";
			for (int c = 0; c < tokens.size(); c++)
				convolve.expr[c] = tokens[c];
			convolve.modify();
			store->addUndoPoint();
		}
	}
	if (function == "transform")
	{
		if (tokens.size() == 1 || tokens.size == 2)
		{
			Transform transform(store->image, selection);
			transform.expr[0] = "x";
			transform.expr[1] = "y";
			for (int c = 0; c < tokens.size(); c++)
				transform.expr[c] = tokens[c];
			transform.modify();
			store->addUndoPoint();
		}
	}
	
}