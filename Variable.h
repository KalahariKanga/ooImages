#pragma once
#include "core.h"
#include "Exception.h"
#include "Colour.h"
#include "Selection.h"
#include "Mask.h"

class Variable
{
public:
	static enum class Type
	{
		Void, Real, Colour, Selection, Mask
	};
	
	Variable(Type t);
	~Variable();
	
	Type type;
	union
	{
		float real;
		Colour* colour;
		Selection* selection;
		Mask* mask;
	};
};
