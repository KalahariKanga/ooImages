#pragma once
#include "core.h"
class Exception
{
public:
	enum class ErrorType
	{
		TYPE_MISMATCH, INSUFFICIENT_ARGUMENTS
	} errortype;
	Exception(ErrorType etype);
	~Exception();
	std::string getErrorString();
};
