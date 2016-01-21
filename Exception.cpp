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
		return std::string("You're being shit. Parser error: type mismatch\n");
	case ErrorType::INSUFFICIENT_ARGUMENTS:
		return std::string("You're being shit. Parser error: insufficient arguments\n");
	case ErrorType::ILLEGAL_OPERATOR:
		return std::string("You're being shit. Parser error: illegal operator\n");
	case ErrorType::ARRAY_ERROR:
		return std::string("You're being shit. Parser error: error accessing array\n");
	case ErrorType::ILLEGAL_NAME:
		return std::string("You're being shit. Parser error: illegal variable name\n");
	case ErrorType::MISMATCHED_BRACKETS:
		return std::string("You're being shit. Parser error: mismatched brackets\n");
	case ErrorType::UNKNOWN_PROPERTY:
		return std::string("You're being shit. Parser error: unknown property\n");
	case ErrorType::UNKNOWN_VARIABLE:
		return std::string("You're being shit. Parser error: unknown variable\n");
	case ErrorType::FILE_SAVE_ERROR:
		return std::string("You're being shit. File Save error\n");
	case ErrorType::FILE_LOAD_ERROR:
		return std::string("You're being shit. File Load error\n");
	case ErrorType::LOOP_ERROR:
		return std::string("You're being shit. Loop error\n");
	default:
		return std::string("You're being shit. Parser error: unknown\n");
	}
}
