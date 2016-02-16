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

void Variable::set(shared_ptr<Resource> newData)
{
	data = newData;
}

void Variable::set(Resource* res)
{
	data.reset(res);
}

Variable Variable::duplicate()
{
	if (type == Type::Void)
		return Variable(Type::Void);

	if (type == Type::Real)
	{
		Variable v(*get<Real>());
		return v;
	}

	Variable v(type);
	v.data.reset(get<Resource>()->clone());
	return v;
}
