#pragma once
#include "Expression.h"
#include "ImageStore.h"

class SelectionCompositionExpression :
	public Expression
{
public:
	SelectionCompositionExpression();
	~SelectionCompositionExpression();
	virtual Variable evaluate();
	bool (*op)(bool, bool);
};

