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
	if (type == Type::Void)
		return Variable(Type::Void);

	if (type == Type::Real)
	{
		Variable v(Type::Real);
		v.set<float>(new float(*get<float>()));
		return v;
	}

	Variable v(type);
	v.data.reset(getResource()->clone());
	return v;
}
