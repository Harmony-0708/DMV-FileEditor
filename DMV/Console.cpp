#include "Console.h"

int Console::Run(CommandObject* object)
{
    GUI gui{};
    std::vector<std::string> commands{ object->get_commands() };
    std::vector<std::string> commandsDef{ object->get_command_defs() };
    std::vector<std::string> combined{ HLib::MergeOrdered(commands,commandsDef) };
    std::string input{};

    system("cls");

    do {
        gui.MakeBox(object->get_title(), 2);
        input.clear();
        std::string command{};
        std::string parameter{};
        std::string bufferCommand{};

        object->Display();

        std::cout << "\n\nEnter input:\n";
        std::cin.clear();
        std::cin.sync();
        std::getline(std::cin, input);

        //seperates the command
        int parameterindex{};
        parameter = input;
        for (char i : input) {
            if (i != ' ') {
                if (std::isalpha(i)) {
                    command.push_back(std::tolower(i));
                    parameter.erase(0, 1);
                }
                else {
                    command.push_back(i);
                    parameter.erase(0, 1);
                }
            }
            else {
                parameter.erase(0, 1);
                break;
            }
        }
        if (HLib::IncludesString(command, commands)) {
            if (command == "help" && parameter == "") {
                object = object->ExecuteCommand(CommandCode(command, object->get_commands()), object, combined, "console");
            }
            else {
                std::vector<std::string> parameters{ HLib::Split(parameter) };
                object = object->ExecuteCommand(CommandCode(command, object->get_commands()), object, parameters);
            }
            input = command;
        }
        else {
            std::cout << "\nInvalid Command, use 'help' for list of commands\n";
        }
    } while (object->IsDone(input));

    return 0;
}


int Console::ValidateCommand(std::string prompt, std::vector<std::string> cmds, std::vector<std::string> cmdDefs, std::vector<std::string>& parameters) {
    GUI gui{};
    std::vector<std::string> options{ "options","cancel" };
    std::vector<std::string> optionDefs{ "Displays options","Cancels action" };
    options.insert(std::end(options), std::begin(cmds), std::end(cmds));
    optionDefs.insert(std::end(optionDefs), std::begin(cmdDefs), std::end(cmdDefs));
    std::string input{};

    if (parameters.empty()) {
        std::cout << "\n" << prompt << "\n";
        std::getline(std::cin, input);
        parameters = HLib::Split(input);
        return 0;
    }
    else if (parameters.at(0) == "options") {
        gui.GenerateMenu("Options", HLib::MergeOrdered(options, optionDefs), "", true, 2);
        std::cout << "\n" << prompt << "\n";
        std::getline(std::cin, input);
        parameters = HLib::Split(input);
        return 0;
    }
    else if (parameters.at(0) == "cancel") {
        return 1;
    }
    else if (HLib::IncludesString(parameters.at(0), options)) {
        return 2;
    }
    else {
        return 3;
    }
}

int Console::CommandCode(std::string command, std::vector<std::string> commands) {
    if (HLib::IncludesString(command, commands)) {
        return HLib::Index(command, commands);
    }
    else {
        return -1;
    }
}
