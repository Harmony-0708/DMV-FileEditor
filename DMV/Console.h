#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "GUI.h"
#include "harmonylib.h"
#include "CommandObject.h"
class Console
{
public:
	Console();
	int Run(CommandObject *object);
	int ValidateCommand(std::string prompt, std::vector<std::string> cmds, std::vector<std::string> cmdDefs, std::vector<std::string>& parameters);
	int CommandCode(std::string command, std::vector<std::string> commands);

};

