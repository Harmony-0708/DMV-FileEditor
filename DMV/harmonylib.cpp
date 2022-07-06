#include "harmonylib.h"
using namespace HLib;

//template <typename T>
//void HLib::remove(std::vector<T>& vec, size_t pos)
//{
//    std::vector<T>::iterator it = vec.begin();
//    std::advance(it, pos);
//    vec.erase(it);
//}

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
		else if (inputString[i+1] == ' ' || inputString[i+1] == ',' || inputString[i+1] == '.' || inputString[i+1] == '!' || inputString[i+1] == '?' || inputString[i+1] == ':' || isalnum(i+1) || isalnum(i)) {
            std::cout << i;
			counter -= 1;
		}
		else {
			std::cout << std::endl;
			counter = 0;
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
                    std::cin >> input;
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
                    std::cin >> input;
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
                    else if (i == ' ' || i == '-') {
                        lowerInput += i;
                    }
                    else {
                        alphacheck = false;
                    }
                }
                if (!(alphacheck) || (std::find(parameters.begin(), parameters.end(), input) == parameters.end()) || input == "") {
                    std::cout << "Invalid input\n" << repeatString;
                    std::cin >> input;
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
                    std::cin >> input;
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
                    std::cin >> input;
                }
                else {
                    check = true;
                }
            } while (check != true);
            return input;
        }
    }
}

