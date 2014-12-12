#include "ExpressionParser.h"

std::map<std::string, double> ExpressionParser::variables;
std::map<std::string, std::string> ExpressionParser::expressions;
ExpressionParser::ExpressionParser()
{
	loadVariables();
}


ExpressionParser::~ExpressionParser()
{
}

void ExpressionParser::loadVariables()
{
	typedef std::map<std::string, double>::iterator iterator; //or auto
	for (iterator it = variables.begin(); it != variables.end(); it++)
	{
		parser.DefineVar(it->first, &(it->second));
	}
}

double ExpressionParser::evaluate()
{
	
	double value = -1;
	try
	{
		value = parser.Eval();
	}
	catch (mu::ParserError error)
	{
		std::cout << "Parser Error! ";
		std::cout << error.GetMsg() << std::endl;
	}
	return value;
}

void ExpressionParser::setString(std::string str)
{
	//replace expression names with expressions
	//TODO:for layered expressions, loop the following while the string contains expression names
	for (auto it = expressions.begin(); it != expressions.end(); it++)
	{
		while (str.find(it->first) != std::string::npos)
			str.replace(str.find(it->first), (it->first).length(), it->second);
	}

	parser.SetExpr(str);
}

void ExpressionParser::updateVariable(std::string name, std::string expr)
{
	//could evaluate the expression on the outside

	//check for name conflicts with expressions
	if (expressions.find(name) != expressions.end())
	{
		return; //probably should throw
	}
	ExpressionParser localParser;
	if (expr == "")
		expr = "0";
	double value;
	localParser.setString(expr);
	try{
		value = localParser.evaluate();
	}
	catch (mu::ParserError)
	{
		std::cout << "Parser Error\n";
	}

	if (!variables.insert(std::pair<std::string, double>(name, value)).second)
		variables[name] = value;
	variables.insert(std::pair<std::string, double>(name, value));
	//loadVariables();
}

void ExpressionParser::updateExpression(std::string name, std::string expr)
{
	if (variables.find(name) != variables.end())
	{
		return; //again, really probably should throw
	}
	expr = "(" + expr + ")";
	if (!expressions.insert(std::pair<std::string, std::string>(name, expr)).second)
		expressions[name] = expr;
	expressions.insert(std::pair<std::string, std::string>(name, expr));
	//loadVariables();
}

void ExpressionParser::addLocalVariable(std::string name, double* location)
{
	parser.DefineVar(name, location);
}