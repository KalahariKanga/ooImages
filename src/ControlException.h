#pragma once
class ControlException
{
public:
	enum class Type { BREAK, CONTINUE };//return?
	const Type type;
	ControlException(Type type);
	~ControlException();
};

