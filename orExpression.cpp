#include "orExpression.h"


orExpression::orExpression()
{
	op = [](bool a, bool b){return (a || b); };
}


orExpression::~orExpression()
{
}
