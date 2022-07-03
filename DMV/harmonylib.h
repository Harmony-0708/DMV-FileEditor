#pragma once
#include <string>
#include <iostream>
#include <vector>


void WordWrap(int wrapLimit, std::string inputString);
std::string InputCheck(std::string input, std::string repeatString, bool onlyAlpha = true, bool onlyNums = false, std::vector<std::string> parameters = {});
//template<typename T>
//void DisplayVector(int wrapLimit, std::vector<T> inputVector);



