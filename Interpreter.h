#pragma once
#include "stdafx.h"
#include "Selection.h"
#include "ImageStore.h"

class Interpreter
{
	std::vector<std::string> commands;
	std::vector<std::string> tokenizeString(std::string);
public:
	Interpreter();
	~Interpreter();
	void interpret(std::string command);
	Selection* selection;
	ImageStore* store;
};

