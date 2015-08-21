#pragma once
#include "muParser.h"
//IF YOURE GETTING THE MU::STRINGTYPE ERROR, CHANGE TO MULTIBYTE CHARACTER SET
//ALSO HOWS EVERYTHING GOING?

class ExpressionParser
{
	mu::Parser parser;
	static std::map<std::string, double> variables;
	static std::map<std::string, std::string> expressions;
	void loadVariables();
	std::string myExpression;
public:
	ExpressionParser();
	~ExpressionParser();
	
	double evaluate();

	void setString(std::string);
	static void updateVariable(std::string name, std::string expr);
	static void updateExpression(std::string name, std::string expr);
	void addLocalVariable(std::string name, double* location);
	
};

