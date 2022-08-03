#pragma once
#include <string>
#include <iostream>
#include <vector>

namespace HLib {

	/*template <typename T>
	void remove(std::vector<T>& vec, size_t pos);*/

	void DisplayVector(int wrapLimit, std::vector<std::string> inputVector);

	void WordWrap(int wrapLimit, std::string inputString);
	std::string InputCheck(std::string input, std::string repeatString, bool onlyAlpha = true, bool onlyNums = false, std::vector<std::string> parameters = {});

	int FindLongest(std::vector<std::string> input, int longestLen = 0);
}





