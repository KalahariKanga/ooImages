#include "andExpression.h"


andExpression::andExpression()
{
	op = [](bool a, bool b){return(a&&b); };
}


andExpression::~andExpression()
{
}

