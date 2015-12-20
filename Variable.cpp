#include "Variable.h"
#include "Function.h"

Variable::Variable(Variable::Type t) : type(t)
{

}

Variable::Variable(const Variable& other)
{
	type = other.type;
	data = other.data;
}

Variable::~Variable()
{
}

void Variable::set(shared_ptr<void> newData)
{
	data = newData;
}

Resource* Variable::getResource()
{
	if (type == Type::Real || type == Type::Void)
		return nullptr;
	else
		return (Resource*)data.get();
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
		v.set(static_pointer_cast<void>(make_shared<Colour>(*get<Colour>())));
		return v;
	}
	case Type::Mask:
	{
		Variable v(Type::Mask);
		v.set(static_pointer_cast<void>(make_shared<Mask>(*get<Mask>())));
		return v;
	}
	case Type::Kernel:
	{
		Variable v(Type::Kernel);
		v.set(static_pointer_cast<void>(make_shared<Kernel>(*get<Kernel>())));
		return v;	
	}
	case Type::Image:
	{
		Variable v(Type::Image);
		v.set(static_pointer_cast<void>(make_shared<ImageObject>(*get<ImageObject>())));
		return v;

	}
	case Type::Function:
	{
		Variable v(Type::Function);
		v.set(static_pointer_cast<void>(make_shared<Function>(*get<Function>())));
		return v;
	}
	default:
		std::cout << "Variable::duplicate() incomplete\n";
		return Variable(Variable::Type::Void);
	}
}
