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
	if (token == "min")
		return new minExpression();
	if (token == "kernel")
		return new kernelExpression();
	if (token == "convolve")
		return new convolveExpression();
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
	if (token == "repeat")
		return new repeatExpression();
	if (token == "while")
		return new whileExpression();
	if (token == "loadImage")
		return new loadImageExpression();
	if (token == "using")
		return new usingExpression();
	if (token == "crop")
		return new cropExpression();
	if (token == "rgba")
		return new rgbaExpression();
	if (token == "blend")
		return new blendExpression();
	if (token == "hsva")
		return new hsvaExpression();
	if (token == "combine")
		return new combineExpression();
	if (token == "gauss")
		return new gaussExpression();
	if (token == "random")
		return new randomExpression();
	if (token == "+")
		return new BinaryOperatorExpression(BinaryOperatorExpression::Operator::ADD);
	if (token == "-")
		return new BinaryOperatorExpression(BinaryOperatorExpression::Operator::SUBTRACT);
	if (token == "*")
		return new BinaryOperatorExpression(BinaryOperatorExpression::Operator::MULTIPLY);
	if (token == "/")
		return new BinaryOperatorExpression(BinaryOperatorExpression::Operator::DIVIDE);
	if (token == "==")
		return new BinaryOperatorExpression(BinaryOperatorExpression::Operator::EQUAL);
	if (token == "<=")
		return new BinaryOperatorExpression(BinaryOperatorExpression::Operator::LESS_EQUAL);
	if (token == ">=")
		return new BinaryOperatorExpression(BinaryOperatorExpression::Operator::GREATER_EQUAL);
	if (token == "<")
		return new BinaryOperatorExpression(BinaryOperatorExpression::Operator::LESS);
	if (token == ">")
		return new BinaryOperatorExpression(BinaryOperatorExpression::Operator::GREATER);
	if (token.back() == '_')
		return new ArrayVariableExpression(token);

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
	head->calculateConstancy();
	return head->getResult();
}