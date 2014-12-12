#include "Interpreter.h"
#include "ExpressionParser.h"
#include "Invert.h"
#include "RgbTransform.h"
#include "HsvTransform.h"
#include "Convolve.h"
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
			*selection = selection->dilate(&Selection::create(tokens, 20, 20), 10, 10);
		else if (op == "erode")
			*selection = selection->erode(&(Selection::create(tokens, 20, 20)), 10, 10);
		else
			*selection = selection->combine(op, &Selection::create(tokens, store->image));
	}
	if (function == "invert")
	{
		Invert invert(store->image, selection);
		invert.modify();
	}
	if (function == "rgb")
	{
		RgbTransform rgb(store->image, selection);
		for (int c = 0; c < 3; c++)
			rgb.expr[c] = tokens[c];
		rgb.modify();
	}
	if (function == "hsv")
	{
		HsvTransform hsv(store->image, selection);
		for (int c = 0; c < 3; c++)
			hsv.expr[c] = tokens[c];
		hsv.modify();
	}
	if (function == "convolve")
	{
		Convolve convolve(store->image, selection);
		for (int c = 0; c < 9; c++)
			convolve.expr[c] = tokens[c];
		convolve.modify();
	}
}