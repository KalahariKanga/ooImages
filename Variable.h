#pragma once
#include "core.h"
#include "Exception.h"
#include "Colour.h"
#include "Selection.h"
#include "Mask.h"
#include "Kernel.h"


class Variable
{
	std::shared_ptr<void> data;
public:
	enum class Type
	{
		Void, Real, Colour, Selection, Mask, Kernel, Image, Function
	};
	
	Variable(Type t = Type::Void);
	Variable(const Variable& other);
	~Variable();
	
	Type type;
	

	template <class T> T* get();
	template <class T> void set(T*);
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

template <class T>
void Variable::set(T* t)
{
	data = make_shared<T>(*t);
}

template <class T>
shared_ptr<T> Variable::getShared()
{
	return static_pointer_cast<T>(data);
}