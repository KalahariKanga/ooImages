#include "Parser.h"


Parser::Parser()
{
}


Parser::~Parser()
{
	delete head;
}

std::vector<std::string> Parser::tokenizeString(std::string string)
{
	std::stringstream stream;
	std::string token;
	std::vector<std::string> list;
	stream << string;
	while (std::getline(stream, token, ' '))
	{
		//TODO:trim tokens for leading and trailing spaces
		list.push_back(token);
	}
	return list;
}

Expression* Parser::tokenToExpression(std::string token)
{
	if (token == "rgb")
		return new rgbExpression();
	if (token == "hsv")
		return new hsvExpression();
	if (token == "setPixels")
		return new setPixelsExpression();
	if (token == "transform")
		return new transformExpression();
	if (token == "select")
		return new selectExpression();
	if (token == "rectangle")
		return new rectangleExpression();
	if (token == "region")
		return new regionExpression();
	if (token == "and")
		return new andExpression();
	if (token == "kernel")
		return new kernelExpression();
	if (token == "convolve")
		return new convolveExpression();

	return new TerminalExpression(token);
}

Variable Parser::run(std::string input)
{
	delete head;
	auto tokens = tokenizeString(input);
	std::vector<Expression*> expressions;
	for (auto t : tokens)
	{
		expressions.push_back(tokenToExpression(t));
	}
	Expression* head = expressions.front()->acquire(&expressions);
	return head->evaluate();
}