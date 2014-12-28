#pragma once
#include "stdafx.h"
#include "Selection.h"
#include "ImageStore.h"

class Interpreter
{
	std::vector<std::string> commands;
	
public:
	std::vector<std::string> tokenizeString(std::string);
	Interpreter();
	~Interpreter();
	void interpret(std::string command);
	
	Mask* mask;
	ImageStore* store;
};

