#include "harmonylib.h"
using namespace HLib;

/// <summary>
/// Wraps the words in the console around a specific limit
/// </summary>
/// <param name="wrapLimit"> Limit of characters per line (does not include prompt)</param>
/// <param name="inputString">String to be displayed</param>
void HLib::WordWrap(int wrapLimit, std::string inputString)
{
    int counter{};
    for (char i : inputString) {
        if (counter < wrapLimit + 1) {
            std::cout << i;
            counter++;
        }
        if (i == ' ' || i == ',' || i == '.' || i == '!' || i == '?' || i == ':') {
            bool check{ false };
            std::string tempString{};
            for (int k{ 0 }; k < 10; k++) {
                if (inputString[i + k] == ' ') {
                    check = true;
                    break;
                }
                tempString += inputString[i + k];
            }
            if (!check) {
                std::cout << std::string(wrapLimit - counter, ' ') << std::endl;
                counter = 0;
            }
            else if (tempString.length() >= (wrapLimit - counter)) {
                std::cout << std::string(wrapLimit - counter, ' ') << std::endl;
                counter = 0;
            }
        }
    }
}

/// <summary>
/// This will display all elements of a std::string vector, if you need new values you must overload in said file
/// </summary>
/// <param name="wrapLimit">How many characters can be displayed before looping</param>
/// <param name="inputVector">The vector to be displayed, elements must be std::string</param>
void HLib::DisplayVector(int wrapLimit, std::vector<std::string> inputVector)
{
    std::string stringOfVector{};
    if (inputVector.empty()) {
        stringOfVector = "None";
    }
    else {
        for (std::string i : inputVector) {
            if (i == inputVector.back()) {
                stringOfVector += i + "\n";
            }
            else {
                stringOfVector += i + ", ";
            }
        }
    }
    HLib::WordWrap(wrapLimit, stringOfVector);
}

/// <summary>
/// This checks a string to a set of parameters or for alpha check
/// </summary>
/// <param name="input">The input string</param>
/// <param name="repeatString">This is the prompt that repeats when user inputs invalid input</param>
/// <param name="onlyAlpha">This will make it so the input has to be alpha characters</param>
/// <param name="onlyNums">This will make it so the input has to be numbers</param>
/// <param name="parameters">Input vector that contains the parameters you want to filter by (they must be strings)</param>
/// <returns></returns>
std::string HLib::InputCheck(std::string input, std::string repeatString, std::vector<std::string> parameters, bool onlyAlpha, bool onlyNums) {
    bool check{};
    if (onlyAlpha && onlyNums) {
        onlyNums = false;
    }
    do {
        bool alphacheck{ false };
        bool numcheck{ false };
        std::string lowerInput{};
        for (char i : input) {
            if (isalpha(i)) {
                lowerInput += tolower(i);
                alphacheck = true;
            }
            else if (!isdigit(i)) {
                lowerInput += i;
                alphacheck = true;
            }
            else {
                lowerInput += i;
                numcheck = true;
            }
        }
        if (onlyAlpha && numcheck) {
            onlyAlpha = false;
        }
        else if (onlyNums && alphacheck) {
            onlyNums = false;
        }
        else if (!onlyNums && !onlyAlpha) {
            onlyAlpha = true;
            onlyNums = true;
        }
        if ((input == "") || (!onlyAlpha && !onlyNums) || (!parameters.empty() && (!IncludesString(input, parameters)))) {
            std::cout << "\nInvalid input\n" << repeatString;
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin, input);
        }
        else {
            check = true;
        }
    } while (check != true);
    return input;
}

/// <summary>
/// Finds the length of the longest string and returns the length, also allows for a basevalue to check from
/// </summary>
/// <param name="input">- Vector of strings to check</param>
/// <param name="longestLen">- Optional length to check from</param>
/// <returns></returns>
int HLib::FindLongest(std::vector<std::string> input, int longestLen)
{
    for (std::string i : input) {
        if (i.length() > longestLen) {
            longestLen = i.length();
        }
    }
    return longestLen;
}

bool HLib::StringToBool(std::string input)
{
    if (input == "true" || input == "True") {
        return true;
    }
    else {
        return false;
    }
}

int HLib::Index(std::string input, std::vector<std::string> inputVector) {
    return (std::distance(inputVector.begin(), std::find(inputVector.begin(), inputVector.end(), input)));
}

void HLib::ExitProgram() {
    std::string input{};
    std::cout << "\nAre you sure you want to exit?\n";
    std::getline(std::cin, input);
    input = InputCheck(input, "\nInput incorrect format\nAre you sure you want to exit?\n", std::vector<std::string>{"yes", "no", "y", "n"}, true, false);
    if (input == "yes" || input == "y") {
        std::cout << "\n\nGoodbye!\n";
        system("pause");
        exit(0);
    }
    else {
        std::cout << "\n\nReturning to console...\n";
        system("pause");
        system("cls");
    }
}

bool HLib::IncludesString(std::string input, std::vector<std::string> vInput) {
    for (std::string i : vInput) {
        if (i == input) {
            return true;
        }
    }
    return false;
}

void HLib::VectorToString(std::vector<std::string>& parameters, std::string& newName)
{
    int index{};
    for (std::string i : parameters) {
        if (index != 0) { newName += " " + parameters.at(index); }
        else { newName += parameters.at(index); }
        index++;
    }
}

std::vector<std::string> HLib::Remove(std::vector<std::string> input, int index) {
    std::vector<std::string> newVector{};
    int counter{};
    for (std::string i : input) {
        if (counter != index) {
            newVector.push_back(i);
        }
        counter++;
    }
    return newVector;
}

std::vector<std::string> HLib::MergeOrdered(std::vector<std::string> command, std::vector<std::string> description) {
    int index{};
    std::vector<std::string> combined{};
    for (std::string i : command) {
        combined.push_back(i);
        combined.push_back(description.at(index));
        index++;
    }
    return combined;
}

std::vector<std::string> HLib::Split(std::string s) {
    std::stringstream ss(s);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings(begin, end);
    return vstrings;
}

std::vector<std::string> HLib::Selection(std::vector<std::string> parameters) {
    GUI selectionGUI{};
    std::vector<std::string> selected{};
    std::string input{};
    std::vector<std::string> commands{ "add","remove","clear","done" };

    do {
        system("cls");

        std::string command{};
        std::string parameter{};

        selectionGUI.GenerateMenu("Enter selections ", parameters, "Use add, remove, and clear", true, 4);

        if (!selected.empty()) {
            std::cout << std::endl;
            selectionGUI.GenerateMenu("Already Selected ", selected, "", true, 4);
        }

        std::cout << "\nEnter input:\n";
        std::cin.clear();
        std::cin.sync();
        std::getline(std::cin, input);

        //seperates the command
        parameter = input;
        int parameterindex{};
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
            if (command == "add") {
                if (parameter != "all") {
                    bool found{ false };
                    for (std::string i : selected) {
                        if (i == parameter) {
                            found = true;
                        }
                    }
                    if (!found) {
                        selected.push_back(parameter);
                    }
                    else {
                        std::cout << "\nItem was already selected\n";
                    }
                }
                else {
                    selected.clear();
                    for (std::string i : parameters) {
                        selected.push_back(i);
                    }
                }
            }
            else if (command == "remove") {
                int index{ -1 };
                bool found{ false };
                for (std::string i : selected) {
                    index++;
                    if (i == parameter) {
                        selected.erase(selected.begin() + index);
                        found = true;
                    }
                }
                if (!found) {
                    std::cout << "\nItem was not found\n";
                }
            }
            else if (command == "clear") {
                std::cout << "\nAre you sure you want to clear your selection?\n";
                input.clear();
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, input);
                input = HLib::InputCheck(input, "\nYes/No\nAre you sure you want to clear your selection?\n", { "Yes","No","yes","no" }, true, false);
                if (input == "yes" || input == "Yes") {
                    selected.clear();
                }
            }
            input = command;
        }
        else {
            std::cout << "\nInvalid Command, use 'help' for list of commands\n";
        }

    } while (input != "done");
    return selected;
}
