#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

namespace HLib {

	/*template <typename T>
	void remove(std::vector<T>& vec, size_t pos);*/

	void DisplayVector(int wrapLimit, std::vector<std::string> inputVector);

	void WordWrap(int wrapLimit, std::string inputString);

	std::string InputCheck(std::string input, std::string repeatString = { "" }, std::vector<std::string> parameters = {}, bool onlyAlpha = true, bool onlyNums = false);

	void ExitProgram();

	int FindLongest(std::vector<std::string> input, int longestLen = 0);

	std::vector<std::string> Remove(std::vector<std::string> input, int index);

	std::vector<std::string> MergeOrdered(std::vector<std::string> command, std::vector<std::string> description);

	std::vector<std::string> Split(std::string s);

	void VectorToString(std::vector<std::string>& parameters, std::string& newName);

	bool IncludesString(std::string input, std::vector<std::string> vInput);

	int Index(std::string input, std::vector<std::string> inputVector);

	bool StringToBool(std::string input);
}





