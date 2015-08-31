#pragma once
#include "core.h"
class Exception
{
public:
	enum class ErrorType
	{
		TYPE_MISMATCH, INSUFFICIENT_ARGUMENTS, PARSER_ERROR
	} errortype;
	Exception(ErrorType etype);
	~Exception();
	std::string getErrorString();
};

