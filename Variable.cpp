#include "Variable.h"

Variable::Variable(Variable::Type t) : type(t)
{

}

Variable::Variable(Variable& other)
{
	type = other.type;
	data = std::move(other.data);
}

Variable::~Variable()
{
	/*switch (type)
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
	}*/

}

