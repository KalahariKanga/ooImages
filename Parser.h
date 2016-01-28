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
#include "minExpression.h"
#include "maxExpression.h"
#include "kernelExpression.h"
#include "convolveExpression.h"
#include "allExpression.h"
#include "getPixelExpression.h"
#include "pointDistanceExpression.h"
#include "pointDirectionExpression.h"
#include "fuzzyExpression.h"
#include "setExpression.h"
#include "SequenceExpression.h"
#include "EndSequenceExpression.h"
#include "ifExpression.h"
#include "repeatExpression.h"
#include "whileExpression.h"
#include "loadImageExpression.h"
#include "usingExpression.h"
#include "cropExpression.h"
#include "rgbaExpression.h"
#include "blendExpression.h"
#include "hsvaExpression.h"
#include "combineExpression.h"
#include "gaussExpression.h"
#include "BinaryOperatorExpression.h"
#include "ArrayVariableExpression.h"
#include "randomExpression.h"
#include "printExpression.h"
#include "createImageExpression.h"
#include "functionExpression.h"
#include "FunctionCallExpression.h"
#include "returnExpression.h"
#include "saveImageExpression.h"
#include "aboutExpression.h"
#include "PropertyAccessorExpression.h"
#include "UnaryFunctionExpression.h"
#include "forExpression.h"
#include "breakExpression.h"
#include "continueExpression.h"
#include "elseExpression.h"
#include "lineExpression.h"

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

