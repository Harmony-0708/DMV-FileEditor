#include "harmonylib.h"


//template<typename T>
void DisplayVector(int wrapLimit, std::vector<std::string> inputVector)
{
    std::string stringOfVector{};
    for (std::string i : inputVector) {
        /*stringOfVector += to_string(i) + ", ";*/
        if (i == inputVector.back()) {
            stringOfVector += i + "\n";
        }
        else {
            stringOfVector += i + ", ";
        }
    }
    WordWrap(wrapLimit, stringOfVector);
}

/// <summary>
/// Wraps the words in the console around a specific limit
/// </summary>
/// <param name="wrapLimit"> Limit of characters per line (does not include prompt)</param>
/// <param name="inputString">String to be displayed</param>
void WordWrap(int wrapLimit, std::string inputString)
{
	int counter{};
	for (char i : inputString) {
		if (counter < wrapLimit + 1) {
			std::cout << i;
			counter++;
		}
		else {
			std::cout << std::endl;
			counter = 0;
		}
	}
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
std::string InputCheck(std::string input, std::string repeatString, bool onlyAlpha, bool onlyNums, std::vector<std::string> parameters) {
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
                    else {
                        alphacheck = false;
                    }
                }
                if (!alphacheck && input != "") {
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
                }
                if (alphacheck && input != "") {
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
                    else {
                        alphacheck = false;
                    }
                }
                if (!(alphacheck) && (std::find(parameters.begin(), parameters.end(), input) == parameters.end()) && input != "") {
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
                }
                if (alphacheck && (std::find(parameters.begin(), parameters.end(), input) == parameters.end()) && input != "") {
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
                if (std::find(parameters.begin(), parameters.end(), input) == parameters.end() && input != "") {
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

