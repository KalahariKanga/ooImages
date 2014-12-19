#include "ScriptManager.h"


ScriptManager::ScriptManager()
{
}


ScriptManager::~ScriptManager()
{
}

void ScriptManager::loadScript(std::ifstream *file)
{
	std::string line;
	
	//ScriptBlock *currentBlock, *previousBlock;
	//currentBlock = &script;

	std::vector<ScriptBlock*> blockHistory;
	blockHistory.push_back(&script);
	
	while (std::getline(*file, line))
	{

		if (line != "[" && line != "]")
		{
			ScriptLine* l = new ScriptLine();
			blockHistory.back()->contents.push_back(l);
			blockHistory.back()->contents.back()->line = line;
		}
		else if (line == "[")
		{
			ScriptBlock* b = new ScriptBlock();
			blockHistory.back()->contents.push_back(b);
			blockHistory.push_back(blockHistory.back()->contents.back());
		}
		else if (line == "]")
		{
			blockHistory.pop_back();
		}

	}


	script.run();
}
