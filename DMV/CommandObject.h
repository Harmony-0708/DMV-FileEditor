#pragma once
#include <vector>
#include <string>
class CommandObject
{
private:
	std::string Title{};
	std::string DoneVariable{};
	std::vector<std::string> Commands{};
	std::vector<std::string> CommandDefs{};
public:
	virtual CommandObject* ExecuteCommand(int cmdCode, CommandObject *object, std::vector<std::string> parameters = {}, std::string context = {}) = 0;
	virtual void Display() = 0;
	virtual std::string get_title() = 0;
	virtual bool IsDone(std::string input) = 0;
	virtual std::vector<std::string> get_commands() = 0;
	virtual std::vector<std::string> get_command_defs() = 0;
};

