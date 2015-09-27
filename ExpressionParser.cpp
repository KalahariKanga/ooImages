#include "ExpressionParser.h"

std::map<std::string, float> ExpressionParser::variables;
std::map<std::string, std::string> ExpressionParser::expressions;
ExpressionParser::ExpressionParser()
{
	loadVariables();
	parser.DefineOprt("mod", [](float a, float b){return (float)((int)a % (int)b); }, 6, mu::EOprtAssociativity::oaLEFT, 1);
	parser.DefineFun("pointDistance", [](float x1, float y1, float x2, float y2)
	{
		return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	});

	parser.DefineFun("pointDirection", [](float x1, float y1, float x2, float y2)
	{
		return (float)(180 * atan2(y2 - y1, x2 - x1) / PI);
	});
	
}


ExpressionParser::~ExpressionParser()
{
}

void ExpressionParser::loadVariables()
{
	typedef std::map<std::string, float>::iterator iterator; //or auto
	for (iterator it = variables.begin(); it != variables.end(); it++)
	{
		parser.DefineVar(it->first, &(it->second));
	}
}

float ExpressionParser::evaluate()
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
		throw new Exception(Exception::ErrorType::PARSER_ERROR);
	}
	return value;
}

void ExpressionParser::setString(std::string str)
{
	//replace expression names with expressions
	//TODO:for layered expressions, loop the following while the string contains expression names
	
	for (auto it = expressions.begin(); it != expressions.end(); it++)
	{
		for (int p = 0; p < str.size(); p++)
		{
			int sp = 0;

			while (sp < it->first.size())
			{
				if (str[p + sp] == it->first[sp])
					sp++;
				else break;
			}

			char next, prev;
			if (p>0)
				prev = str[p - 1];
			else
				prev = '\0';
			if (p + it->first.size() < str.length() - 1)
				next = str[p + it->first.size()];
			else next = '\0';

			if (sp == it->first.size() && !isalnum(next) && !isalnum(prev))
			{
				str.replace(p, it->first.size(), it->second);
				p = p + it->second.size() - 1;
			}
		}


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

	if (!variables.insert(std::pair<std::string, float>(name, value)).second)
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

void ExpressionParser::addLocalVariable(std::string name, float* location)
{
	parser.DefineVar(name, location);
}