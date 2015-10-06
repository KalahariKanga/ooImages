#pragma once
#include "core.h"
class Exception
{
public:
	enum class ErrorType
	{
		TYPE_MISMATCH, INSUFFICIENT_ARGUMENTS, PARSER_ERROR, VARIABLE_MOVE_ERROR, MISMATCHED_BRACKETS
	} errortype;
	Exception(ErrorType etype);
	~Exception();
	std::string getErrorString();
};

