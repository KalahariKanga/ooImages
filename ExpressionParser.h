#pragma once
#include "muParser.h"
//IF YOURE GETTING THE MU::STRINGTYPE ERROR, CHANGE TO MULTIBYTE CHARACTER SET
//ALSO HOWS EVERYTHING GOING?

#include "Exception.h"

class ExpressionParser
{
	mu::Parser parser;
	static std::map<std::string, float> variables;
	static std::map<std::string, std::string> expressions;
	void loadVariables();
	std::string myExpression;
public:
	ExpressionParser();
	~ExpressionParser();
	
	float evaluate();

	void setString(std::string);
	static void updateVariable(std::string name, std::string expr);
	static void updateExpression(std::string name, std::string expr);
	void addLocalVariable(std::string name, float* location);
	
};

