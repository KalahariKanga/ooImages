#include "Variable.h"
#include "Function.h"

Variable::Variable()
{

}

Variable::Variable(float v)
{
	data = std::make_shared<Real>(v);
}

Variable::Variable(Resource* res)
{
	set(res);
}

Variable::Variable(const Variable& other)
{
	data = other.data;
}

Variable::~Variable()
{
}

void Variable::set(std::shared_ptr<Resource> newData)
{
	data = newData;
}

void Variable::set(Resource* res)
{
	data.reset(res);
}

bool Variable::isNull()
{
	return (bool)!data;
}

Variable Variable::duplicate()
{
	if (isNull())
		return Variable();

	Variable v;
	v.data.reset(get<Resource>()->clone());
	return v;
}
