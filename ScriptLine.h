#pragma once
#include "ScriptBlock.h"
class ScriptLine :
	public ScriptBlock
{
public:
	ScriptLine();
	ScriptLine(std::string string);
	~ScriptLine();
};

