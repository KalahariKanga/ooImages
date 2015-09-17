#include "Variable.h"

Variable::Variable(Variable::Type t) : type(t)
{

}

Variable::~Variable()
{
	switch (type)
	{
	case Type::Colour:
		delete colour;
		break;
	case Type::Selection:
		delete selection;
		break;
	case Type::Mask:
		delete mask;
		break;
	}

}

Colour* Variable::moveColour()
{
	Colour* temp = colour;
	colour = nullptr;
	return temp;
}

Selection* Variable::moveSelection()
{
	Selection* temp = selection;
	selection = nullptr;
	return temp;
}

Mask* Variable::moveMask()
{
	Mask* temp = mask;
	mask = nullptr;
	return temp;
}

Kernel* Variable::moveKernel()
{
	Kernel* temp = kernel;
	mask = nullptr;
	return temp;
}