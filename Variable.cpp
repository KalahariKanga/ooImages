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
}

Variable Variable::duplicate()
{
	switch(type)
	{
	case Type::Void:
		return Variable(Type::Void);
	case Type::Real:
	{
		Variable v(Type::Real);
		v.set<float>(new float(*get<float>()));
		return v;
	}
	case Type::Colour:
	{
		Variable v(Type::Colour);
		v.set<Colour>(new Colour(*get<Colour>()));
		return v;
	}
	default:
		std::cout << "Variable::duplicate() incomplete\n";
		break;
	}
}