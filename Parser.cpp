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