#include "Exception.h"


Exception::Exception(Exception::ErrorType etype) : errortype(etype)
{
}


Exception::~Exception()
{
}

std::string Exception::getErrorString()
{
	switch (errortype)
	{
	case ErrorType::TYPE_MISMATCH:
		return std::string("Parser error: type mismatch\n");
	case ErrorType::INSUFFICIENT_ARGUMENTS:
		return std::string("Parser error: insufficient arguments\n");
	case ErrorType::ILLEGAL_OPERATOR:
		return std::string("Parser error: illegal operator\n");
	case ErrorType::ARRAY_ERROR:
		return std::string("Parser error: error accessing array\n");
	case ErrorType::ILLEGAL_NAME:
		return std::string("Parser error: illegal variable name\n");
	case ErrorType::MISMATCHED_BRACKETS:
		return std::string("Parser error: mismatched brackets\n");
	case ErrorType::UNKNOWN_PROPERTY:
		return std::string("Parser error: unknown property\n");
	case ErrorType::UNKNOWN_VARIABLE:
		return std::string("Parser error: unknown variable\n");
	case ErrorType::FILE_SAVE_ERROR:
		return std::string("File Save error\n");
	default:
		return std::string("Parser error: unknown\n");
	}
}