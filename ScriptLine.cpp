#include "ScriptLine.h"


ScriptLine::ScriptLine()
{
}

ScriptLine::ScriptLine(std::string string)
{
	line = string;
}


ScriptLine::~ScriptLine()
{
}

void ScriptLine::run()
{
	std::cout << line << std::endl;
}