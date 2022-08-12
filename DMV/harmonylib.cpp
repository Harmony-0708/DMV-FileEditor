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
std::string HLib::InputCheck(std::string input, std::string repeatString, bool onlyAlpha, bool onlyNums, std::vector<std::string> parameters) {
    bool check{};
    if (parameters.empty()) {
        if (onlyAlpha) {
            do {
                bool alphacheck{ true };
                std::string lowerInput{};
                for (char i : input) {
                    if (isalpha(i)) {
                        lowerInput += tolower(i);
                    }
                    else if(i == ' ' || i == '-') {
                        lowerInput += i;
                    }
                    else {
                        alphacheck = false;
                    }
                }
                if (!alphacheck || input == "") {
                    std::cout << "Only use alphabet characters\n" << repeatString;
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
        else if (onlyNums) {
            do {
                bool alphacheck{ false };
                for (char i : input) {
                    if (isalpha(i)) {
                        alphacheck = true;
                    }
                    else if (i == ' ') {
                        alphacheck = true;
                    }
                }
                if (alphacheck || input == "") {
                    std::cout << "Only use numbers\n" << repeatString;
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
        else {
            return input;
        }
    }
    else {
        if (onlyAlpha) {
            do {
                bool alphacheck{ true };
                std::string lowerInput{};
                for (char i : input) {
                    if (isalpha(i)) {
                        lowerInput += tolower(i);
                    }
                    else if (i == ' ' || i == '-' || i == '\'') {
                        lowerInput += i;
                    }
                    else {
                        alphacheck = false;
                    }
                }
                if (!(alphacheck) || (std::find(parameters.begin(), parameters.end(), input) == parameters.end()) || input == "") {
                    std::cout << "Invalid input\n" << repeatString;
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
        else if (onlyNums) {
            do {
                bool alphacheck{ false };
                for (char i : input) {
                    if (isalpha(i)) {
                        alphacheck = true;
                    }
                    else if (i == ' ' || i == '-') {
                        alphacheck = true;
                    }
                }
                if (alphacheck || (std::find(parameters.begin(), parameters.end(), input) == parameters.end()) || input == "") {
                    std::cout << "Invalid input\n" << repeatString;
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
        else {
            do {
                if (std::find(parameters.begin(), parameters.end(), input) == parameters.end() || input == "") {
                    std::cout << "Invalid input\n" << repeatString;
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
    }
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

