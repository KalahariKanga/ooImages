#pragma once
#include "core.h"
#include "VariableStore.h"
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
#include "minExpression.h"
#include "kernelExpression.h"
#include "convolveExpression.h"
#include "orExpression.h"
#include "maskExpression.h"
#include "allExpression.h"
#include "getPixelExpression.h"
#include "pointDistanceExpression.h"
#include "pointDirectionExpression.h"
#include "fuzzyExpression.h"
#include "setExpression.h"
#include "VariableExpression.h"
#include "SequenceExpression.h"
#include "EndSequenceExpression.h"
#include "ifExpression.h"

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

