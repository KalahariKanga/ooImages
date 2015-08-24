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
	default:
		return std::string("Parser error: unknown\n");
	}
}