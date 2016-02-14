#pragma once
#include "core.h"
#include "Exception.h"
#include "Colour.h"
#include "Mask.h"
#include "Kernel.h"
#include "ImageObject.h"
#include "Real.h"


class Variable
{
	std::shared_ptr<Resource> data;
public:
	enum class Type
	{
		Void, Real, Colour, Mask, Kernel, Image, Function
	};
	
	Variable(Type t = Type::Void);
	Variable(float v)
	{
		type = Type::Real;
		data = make_shared<Real>(v);
	}
	Variable(const Variable& other);
	~Variable();
	
	Type type;
	

	template <class T> T* get();
	void set(Resource* res);
	void set(shared_ptr<Resource> newData);
	template <class T> shared_ptr<T> getShared();
	Resource* getResource();
	Variable duplicate();
};

template <class T>
T* Variable::get()
{
	//if(type match)
	return (T*)data.get();
}

//template <class T>
//void Variable::set(T* t)
//{
//	data = make_shared<T>(*t);
//}

template <class T>
shared_ptr<T> Variable::getShared()
{
	return static_pointer_cast<T>(data);
}