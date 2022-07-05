#pragma once
#include <string>
#include <iostream>
#include <vector>

//template<typename T>
//void DisplayVector(int wrapLimit, std::vector<T> inputVector);
void DisplayVector(int wrapLimit, std::vector<std::string> inputVector);

void WordWrap(int wrapLimit, std::string inputString);
std::string InputCheck(std::string input, std::string repeatString, bool onlyAlpha = true, bool onlyNums = false, std::vector<std::string> parameters = {});




