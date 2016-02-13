#include "randomExpression.h"

std::default_random_engine randomExpression::engine;
randomExpression::randomExpression()
{
	noArguments = 2;
	optimisable = 0;
}


randomExpression::~randomExpression()
{
}

Variable randomExpression::evaluate()
{
	float from = *arguments[0]->getResult().get<Real>();
	float to = *arguments[1]->getResult().get<Real>();
	std::uniform_real_distribution<float> dist(from, to);
	Variable var(Variable::Type::Real);
	var.set<float>(new float(dist(engine)));
	return var;
}
