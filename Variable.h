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
	
	Variable();
	Variable(float v);
	Variable(Resource* res);
	Variable(const Variable& other);
	~Variable();
	
	template <class T> T* get();
	template <class T> std::shared_ptr<T> getShared();
	void set(Resource* res);
	void set(std::shared_ptr<Resource> newData);
	
	bool isNull();
	template <class T> bool isType();

	Variable duplicate();
};

template <class T>
T* Variable::get()
{
	auto ptr = dynamic_cast<T*>(data.get());
	if (!ptr)
		throw new Exception(Exception::ErrorType::TYPE_MISMATCH);
	return ptr;
}

template <class T>
std::shared_ptr<T> Variable::getShared()
{
	return std::static_pointer_cast<T>(data);
}

template <class T>
bool Variable::isType()
{
	if (dynamic_cast<T*>(data.get()))
		return 1;
	return 0;
}