#pragma once
#include "ScriptLine.h"
#include "Interpreter.h"

class ScriptManager
{
public:
	void loadScript(std::ifstream *file);
	ScriptManager();
	~ScriptManager();
	ScriptBlock script;
	void runBlock(ScriptBlock* block);
	Interpreter *interpreter;
	int interpret(ScriptBlock* block, std::string line, int position);
};

