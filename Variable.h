#pragma once
#include "core.h"
#include "Exception.h"
#include "Colour.h"
#include "Selection.h"
#include "Mask.h"
#include "Kernel.h"

class Variable
{
public:
	static enum class Type
	{
		Void, Real, Colour, Selection, Mask, Kernel, Image, Function
	};
	
	Variable(Type t = Type::Void);
	Variable(Variable& other);
	~Variable();
	
	Type type;
	std::shared_ptr<void> data;

	template <class T> T* get();
	template <class T> void set(T*);

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