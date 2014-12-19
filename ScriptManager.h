#pragma once
#include "ScriptLine.h"

class ScriptManager
{
public:
	void loadScript(std::ifstream *file);
	ScriptManager();
	~ScriptManager();
	ScriptBlock script;
};

