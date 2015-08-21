#pragma once
#include "core.h"
#include "Expression.h"
#include "rgbExpression.h"
#include "TerminalExpression.h"

class Parser
{
	std::vector<std::string> tokenizeString(std::string string);
public:
	Parser();
	~Parser();
	
	Expression* tokenToExpression(std::string);
	Variable run(std::string input);
};

