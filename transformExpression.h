#pragma once
#include "ImageModifierExpression.h"
#include "ImageStore.h"
class transformExpression :
	public ImageModifierExpression
{
public:
	transformExpression();
	~transformExpression();
	Variable evaluate();
};

