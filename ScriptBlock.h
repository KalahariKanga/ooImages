#pragma once
#include "stdafx.h"

class ScriptBlock
{	
public:
	std::string line;
	ScriptBlock();
	~ScriptBlock();
	std::vector<ScriptBlock*> contents; //maybe accesors

};

