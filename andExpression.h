#pragma once
#include "SelectionCompositionExpression.h"

class andExpression :
	public SelectionCompositionExpression
{
public:
	andExpression();
	~andExpression();
	//virtual Variable evaluate();
};
