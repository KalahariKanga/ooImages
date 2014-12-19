#include "ScriptBlock.h"


ScriptBlock::ScriptBlock()
{
}


ScriptBlock::~ScriptBlock()
{
}

void ScriptBlock::run()
{
	for (auto i = contents.begin(); i != contents.end(); i++)
		(*i)->run();
}