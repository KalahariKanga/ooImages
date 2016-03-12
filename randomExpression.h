#pragma once
#include "Expression.h"
#include <random>
class randomExpression :
	public Expression
{
	static std::default_random_engine engine;
	
public:
	randomExpression();
	~randomExpression();
	virtual Variable evaluate();
};

