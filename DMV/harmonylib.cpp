#include "harmonylib.h"


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

//template<typename T>
//void DisplayVector(int wrapLimit, std::vector<T> inputVector)
//{
//	std::string stringOfVector{};
//	for (var i : inputVector) {
//		stringOfVector += to_string(i) + ", ";
//	}
//	WordWrap(wrapLimit, stringOfVector);
//
//}
