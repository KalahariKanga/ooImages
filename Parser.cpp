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
	if (token == "min")
		return new minExpression();
	if (token == "kernel")
		return new kernelExpression();
	if (token == "convolve")
		return new convolveExpression();
	if (token == "or")
		return new orExpression();
	if (token == "mask")
		return new maskExpression();
	if (token == "all")
		return new allExpression();
	if (token == "getPixel")
		return new getPixelExpression();
	if (token == "pointDistance")
		return new pointDistanceExpression();
	if (token == "pointDirection")
		return new pointDirectionExpression();
	if (token == "fuzzy")
		return new fuzzyExpression();
	if (token == "set")
		return new setExpression();
	if (token == "[")
		return new SequenceExpression();
	if (token == "]")
		return new EndSequenceExpression();
	if (token == "if")
		return new ifExpression();

	if (VariableStore::get()->variableExists(token))
		return new VariableExpression(token);
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