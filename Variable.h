#pragma once
#include "core.h"
#include "Exception.h"
#include "Colour.h"
#include "Selection.h"
#include "Mask.h"
#include "Kernel.h"

class Variable
{
public:
	static enum class Type
	{
		Void, Real, Colour, Selection, Mask, Kernel
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
		Kernel* kernel;
	};

	Colour* moveColour();
	Selection* moveSelection();
	Mask* moveMask();
	Kernel* moveKernel();
	//surely these can be templated?

};