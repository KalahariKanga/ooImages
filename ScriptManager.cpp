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
}

void ScriptManager::runBlock(ScriptBlock* block)
{
	int pos = 0;
	for (int c = 0; c < block->contents.size(); c++)
	{
		if (block->contents[c]->contents.size() > 0)
		{
			runBlock(block->contents[c]);
		}
		else
			c = interpret(block, block->contents[c]->line, c);

		
	}
}

int ScriptManager::interpret(ScriptBlock* block, std::string line, int position)
{
	std::vector<std::string> tokens;
	tokens = interpreter->tokenizeString(line);
	if (tokens.size() == 0)
		return position;
	std::string function = tokens.front();
	tokens.erase(tokens.begin());

	if (function == "repeat")
	{
		ExpressionParser parser;
		parser.setString(tokens.front());
		int n = parser.evaluate();
		if (position + 1 < block->contents.size() && n > 0)
		{
			ScriptBlock* next = block->contents[position + 1];
			for (int c = 0; c < n; c++)
				runBlock(next);
		}
		return position+1;
	}
	else if (function == "if")
	{
		ExpressionParser parser;
		parser.setString(tokens.front());
		if (parser.evaluate())
		{
			ScriptBlock* next = block->contents[position + 1];
			runBlock(next);
		}
		return position+1;
	}
	else if (function == "while")
	{
		ExpressionParser parser;
		parser.setString(tokens.front());
		while (parser.evaluate())
		{
			ScriptBlock* next = block->contents[position + 1];
			runBlock(next);
		}
		return position + 1;
	}
	else
		interpreter->interpret(line);
	
	return position;
}

void ScriptManager::run()
{
	runBlock(&script);
}