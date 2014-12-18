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
		//TODO: dont assume the correct number of tokens
		ExpressionParser::updateVariable(tokens.front(), tokens.back());
	}
	if (function == "expr")
	{
		ExpressionParser::updateExpression(tokens.front(), tokens.back());
	}
	if (function == "eval")
	{
		ExpressionParser parser;
		parser.setString(tokens.front());
		std::cout << tokens.front() << ": " << parser.evaluate() << std::endl;
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
		RgbTransform rgb(store->image, selection);
		for (int c = 0; c < 3; c++)
			rgb.expr[c] = tokens[c];
		rgb.modify();
		store->addUndoPoint();
	}
	if (function == "hsv")
	{
		HsvTransform hsv(store->image, selection);
		for (int c = 0; c < 3; c++)
			hsv.expr[c] = tokens[c];
		hsv.modify();
		store->addUndoPoint();
	}
	if (function == "convolve")
	{
		Convolve convolve(store->image, selection);
		for (int c = 0; c < 9; c++)
			convolve.expr[c] = tokens[c];
		convolve.modify();
		store->addUndoPoint();
	}
	if (function == "transform")
	{
		Transform transform(store->image, selection);
		for (int c = 0; c < 2; c++)
			transform.expr[c] = tokens[c];
		transform.modify();
		store->addUndoPoint();
	}
	
}