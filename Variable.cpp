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
	case Type::Kernel:
		delete kernel;
		break;
	}

}

Colour* Variable::moveColour()
{
	if (type != Type::Colour)
		throw new Exception(Exception::ErrorType::VARIABLE_MOVE_ERROR);
	Colour* temp = colour;
	colour = nullptr;
	return temp;
}

Selection* Variable::moveSelection()
{
	if (type != Type::Selection)
		throw new Exception(Exception::ErrorType::VARIABLE_MOVE_ERROR);
	Selection* temp = selection;
	selection = nullptr;
	return temp;
}

Mask* Variable::moveMask()
{
	if (type != Type::Mask)
		throw new Exception(Exception::ErrorType::VARIABLE_MOVE_ERROR);
	Mask* temp = mask;
	mask = nullptr;
	return temp;
}

Kernel* Variable::moveKernel()
{
	if (type != Type::Kernel)
		throw new Exception(Exception::ErrorType::VARIABLE_MOVE_ERROR);
	Kernel* temp = kernel;
	mask = nullptr;
	return temp;
}