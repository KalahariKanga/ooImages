#pragma once
#include "core.h"
class Exception
{
public:
	enum class ErrorType
	{
		TYPE_MISMATCH, INSUFFICIENT_ARGUMENTS, PARSER_ERROR, MISMATCHED_BRACKETS
		,ILLEGAL_OPERATOR, UNKNOWN_PROPERTY, ARRAY_ERROR, UNKNOWN_VARIABLE, ILLEGAL_NAME
	} errortype;
	Exception(ErrorType etype);
	~Exception();
	std::string getErrorString();
};

