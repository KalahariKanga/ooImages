#include "Parser.h"
#include "ControlException.h"

Parser::Parser()
{
	
}


Parser::~Parser()
{
}

void Parser::removeComments(std::string& str)
{
	std::string output;
	bool inQuotes = 0, inComment = 0;

	if (str.empty())
		return;

	for (auto c : str)
	{
		if (c == '"' && !inComment)
			inQuotes = !inQuotes;
		if (c == '#' && !inQuotes)
			inComment = !inComment;
		else if (!inComment)
			output.push_back(c);
	}
	str = output;
}

std::vector<std::string> Parser::tokenizeString(std::string str)
{
	std::vector<std::string> list;
	std::string currentToken = "";
	bool inQuotes = 0;
	
	if (str.empty())
		return list;

	for (auto c : str)
	{
		if (isspace(c) && !inQuotes)
		{
			if (currentToken != "")
			{
				list.push_back(currentToken);
				currentToken = "";
			}
			continue;
		}

		if (c == '"')
			inQuotes = !inQuotes;
		else
			currentToken.push_back(c);
	}
	list.push_back(currentToken);

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
	if (token == "max")
		return new maxExpression();
	if (token == "kernel")
		return new kernelExpression();
	if (token == "convolve")
		return new convolveExpression();
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
	if (token == "print")
		return new printExpression();
	if (token == "createImage")
		return new createImageExpression();
	if (token == "function")
		return new functionExpression();
	if (token == "return")
		return new returnExpression();
	if (token == "saveImage")
		return new saveImageExpression();
	if (token == "about")
		return new aboutExpression();
	if (token == "for")
		return new forExpression();
	if (token == "break")
		return new breakExpression();
	if (token == "continue")
		return new continueExpression();
	if (token == "else")
		return new elseExpression();
	if (token == "line")
		return new lineExpression();
	if (token == "import")
		return new importExpression();
	if (token == "erode")
		return new erodeExpression();
	if (token == "dilate")
		return new dilateExpression();
	if (token == "transformTo")
		return new transformToExpression();
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
	if (token == "%")
		return new BinaryOperatorExpression(BinaryOperatorExpression::Operator::MOD);
	if (token == "&&")
		return new BinaryOperatorExpression(BinaryOperatorExpression::Operator::AND);
	if (token == "||")
		return new BinaryOperatorExpression(BinaryOperatorExpression::Operator::OR);
	if (token == "sin")
		return new UnaryFunctionExpression(UnaryFunctionExpression::FunctionType::SIN);
	if (token == "cos")
		return new UnaryFunctionExpression(UnaryFunctionExpression::FunctionType::COS);
	if (token == "tan")
		return new UnaryFunctionExpression(UnaryFunctionExpression::FunctionType::TAN);
	if (token == "exp")
		return new UnaryFunctionExpression(UnaryFunctionExpression::FunctionType::EXP);
	if (token == "log")
		return new UnaryFunctionExpression(UnaryFunctionExpression::FunctionType::LOG);
	if (token == "ln")
		return new UnaryFunctionExpression(UnaryFunctionExpression::FunctionType::LN);
	if (token.back() == '_')
		return new ArrayVariableExpression(token);
	if (token.back() == '[')
		return new FunctionCallExpression(token);
	if (token.back() == '.')
		return new PropertyAccessorExpression(token);
	
	return new TerminalExpression(token);
}

Variable Parser::run(std::string input)
{
	removeComments(input);
	auto tokens = tokenizeString(input);
	std::vector<std::shared_ptr<Expression>> expressions;
	std::vector<std::shared_ptr<Expression>> expressionStack;
	for (auto t : tokens)
	{
		shared_ptr<Expression> exp;
		exp.reset(tokenToExpression(t));
		expressions.push_back(exp);
	}
	expressionStack = expressions;
	if (!expressions.empty())
	{
		Expression* head = expressions.front()->acquire(&expressionStack);
		head->calculateConstancy();
		try
		{
			return head->getResult();
		}
		catch (Variable v)
		{
			return v;
		}
		catch (ControlException ce)
		{
			throw new Exception(Exception::ErrorType::LOOP_ERROR);
		}
	}
	return Variable();
}