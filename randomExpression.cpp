#include "randomExpression.h"


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
	float from = *arguments[0]->getResult().get<float>();
	float to = *arguments[1]->getResult().get<float>();
	std::uniform_real_distribution<float> dist(from, to);
	Variable var(Variable::Type::Real);
	var.set<float>(new float(dist(engine)));
	return var;
}
