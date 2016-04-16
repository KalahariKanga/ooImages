#pragma once
#include "ImageModifierExpression.h"
class flattenExpression :
	public ImageModifierExpression
{
public:
	flattenExpression();
	~flattenExpression();
	virtual Variable evaluate();
};

