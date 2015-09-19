#pragma once
#include "core.h"
#include "Exception.h"
#include "Expression.h"
#include "rgbExpression.h"
#include "TerminalExpression.h"
#include "setPixelsExpression.h"
#include "hsvExpression.h"
#include "transformExpression.h"
#include "selectExpression.h"
#include "rectangleExpression.h"
#include "regionExpression.h"
#include "andExpression.h"
#include "kernelExpression.h"
#include "convolveExpression.h"
#include "orExpression.h"
#include "maskExpression.h"
#include "allExpression.h"

class Parser
{
	std::vector<std::string> tokenizeString(std::string string);
	Expression* head = nullptr;
public:
	Parser();
	~Parser();
	
	Expression* tokenToExpression(std::string);
	Variable run(std::string input);
};

