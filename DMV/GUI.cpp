#include "GUI.h"

/// <summary>
/// Creates a border around the input, depending on the style.
/// </summary>
/// <param name="input">- The input parameter</param>
/// <param name="style">- 0 double line, 1 single line, 2 bold line, 3 thick sides, 4 thick top and bottom</param>
/// <param name="wordWrap">- Defines whether the text is wrapped</param>
/// <param name="wordWrapLimit">- Defines how much the text is wrapped by</param>
void GUI::MakeBox(int input, int style, bool wordWrap, int wordWrapLimit)
{
	std::string inputString{};
	inputString = std::to_string(input);
	MakeBox(inputString, style, wordWrap, wordWrapLimit);
}
/// <summary>
/// Creates a border around the input, depending on the style.
/// </summary>
/// <param name="input">- The input parameter</param>
/// <param name="style">- 0 double line, 1 single line, 2 bold line, 3 thick sides, 4 thick top and bottom</param>
/// <param name="wordWrap">- Defines whether the text is wrapped</param>
/// <param name="wordWrapLimit">- Defines how much the text is wrapped by</param>
void GUI::MakeBox(float input, int style, bool wordWrap, int wordWrapLimit)
{
	std::string inputString{};
	inputString = std::to_string(input);
	MakeBox(inputString, style, wordWrap, wordWrapLimit);
}
/// <summary>
/// Creates a border around the input, depending on the style.
/// </summary>
/// <param name="input">- The input parameter</param>
/// <param name="style">- 0 double line, 1 single line, 2 bold line, 3 thick sides, 4 thick top and bottom</param>
/// <param name="wordWrap">- Defines whether the text is wrapped</param>
/// <param name="wordWrapLimit">- Defines how much the text is wrapped by</param>
void GUI::MakeBox(std::string input, int style, bool wordWrap, int wordWrapLimit)
{
	char deadSwitch{ '@' };
	if (wordWrap) {
		input += deadSwitch;
	}
	switch (style) {
	case 0: {
		if (wordWrap && wordWrapLimit < input.length()) {
			int counter{ 1 };
			std::cout << (char)cornertplf << std::string(wordWrapLimit + 2, (char)across) << (char)cornertprt << std::endl;
			for (char i : input) {
				if (counter == 1) {
					std::cout << (char)straightline << " " << i;
				}
				else if (counter != 1 && counter != wordWrapLimit) {
					if (i != deadSwitch) {
						std::cout << i;
					}
					else {
						for (int k{ 0 }; k < (wordWrapLimit - counter + 1); k++) {
							std::cout << " ";
						}
						std::cout << " " << (char)straightline << std::endl;
					}
				}
				else if (counter == wordWrapLimit) {
					std::cout << i << " " << (char)straightline << std::endl;
					counter = 0;
				}
				counter++;
			}
			std::cout << (char)cornerbtlf << std::string(wordWrapLimit + 2, (char)across) << (char)cornerbtrt << std::endl;
		}
		else {
		std::cout
			<< (char)cornertplf << std::string(input.length() + 2, (char)across) << (char)cornertprt << std::endl
			<< (char)straightline << " " << input << " " << (char)straightline << std::endl
			<< (char)cornerbtlf << std::string(input.length() + 2, (char)across) << (char)cornerbtrt << std::endl;
		}
		break;
	}
	case 1: {
		if (wordWrap && wordWrapLimit < input.length()) {
			int counter{ 1 };
			std::cout << (char)lightcornertplf << std::string(wordWrapLimit + 2, (char)lightacross) << (char)lightcornertprt << std::endl;
			for (char i : input) {
				if (counter == 1) {
					std::cout << (char)lightstraightline << " " << i;
				}
				else if (counter != 1 && counter != wordWrapLimit) {
					if (i != deadSwitch) {
						std::cout << i;
					}
					else {
						for (int k{ 0 }; k < (wordWrapLimit - counter + 1); k++) {
							std::cout << " ";
						}
						std::cout << " " << (char)lightstraightline << std::endl;
					}
				}
				else if (counter == wordWrapLimit) {
					std::cout << i << " " << (char)lightstraightline << std::endl;
					counter = 0;
				}
				counter++;
			}
			std::cout << (char)lightcornerbtlf << std::string(wordWrapLimit + 2, (char)lightacross) << (char)lightcornerbtrt << std::endl;
		}
		else {
			std::cout
				<< (char)lightcornertplf << std::string(input.length() + 2, (char)lightacross) << (char)lightcornertprt << std::endl
				<< (char)lightstraightline << " " << input << " " << (char)lightstraightline << std::endl
				<< (char)lightcornerbtlf << std::string(input.length() + 2, (char)lightacross) << (char)lightcornerbtrt << std::endl;
		}
		break;
	}
	case 2: {
		if (wordWrap && wordWrapLimit < input.length()) {
			int counter{ 1 };
			std::cout << (char)thickfull << std::string(wordWrapLimit + 2, (char)thicktop) << (char)thickfull << std::endl;
			for (char i : input) {
				if (counter == 1) {
					std::cout << (char)thickfull << " " << i;
				}
				else if (counter != 1 && counter != wordWrapLimit) {
					if (i != deadSwitch) {
						std::cout << i;
					}
					else {
						for (int k{ 0 }; k < (wordWrapLimit - counter + 1); k++) {
							std::cout << " ";
						}
						std::cout << " " << (char)thickfull << std::endl;
					}
				}
				else if (counter == wordWrapLimit) {
					std::cout << i << " " << (char)thickfull << std::endl;
					counter = 0;
				}
				counter++;
			}
			std::cout << (char)thickfull << std::string(wordWrapLimit + 2, (char)thickbottom) << (char)thickfull << std::endl;
		}
		else {
		std::cout
			<< (char)thickfull << std::string(input.length() + 2, (char)thicktop) << (char)thickfull << std::endl
			<< (char)thickfull << " " << input << " " << (char)thickfull << std::endl
			<< (char)thickfull << std::string(input.length() + 2, (char)thickbottom) << (char)thickfull << std::endl;
		}
		break;
	}
	case 3: {
		if (wordWrap && wordWrapLimit < input.length()) {
			int counter{ 1 };
			std::cout << (char)thicktothincornertplf << std::string(wordWrapLimit + 2, (char)lightacross) << (char)thintothickcornertprt << std::endl;
			for (char i : input) {
				if (counter == 1) {
					std::cout << (char)straightline << " " << i;
				}
				else if (counter != 1 && counter != wordWrapLimit) {
					if (i != deadSwitch) {
						std::cout << i;
					}
					else {
						for (int k{ 0 }; k < (wordWrapLimit - counter + 1); k++) {
							std::cout << " ";
						}
						std::cout << " " << (char)straightline << std::endl;
					}
				}
				else if (counter == wordWrapLimit) {
					std::cout << i << " " << (char)straightline << std::endl;
					counter = 0;
				}
				counter++;
			}
			std::cout << (char)thicktothincornerbtlf << std::string(wordWrapLimit + 2, (char)lightacross) << (char)thintothickcornerbtrt << std::endl;
		}
		else {
			std::cout
				<< (char)thicktothincornertplf << std::string(input.length() + 2, (char)lightacross) << (char)thintothickcornertprt << std::endl
				<< (char)straightline << " " << input << " " << (char)straightline << std::endl
				<< (char)thicktothincornerbtlf << std::string(input.length() + 2, (char)lightacross) << (char)thintothickcornerbtrt << std::endl;
		}
		break;
	}
	case 4: {
		if (wordWrap && wordWrapLimit < input.length()) {
			int counter{ 1 };
			std::cout << (char)thintothickcornertplf << std::string(wordWrapLimit + 2, (char)across) << (char)thicktothincornertprt << std::endl;
			for (char i : input) {
				if (counter == 1) {
					std::cout << (char)lightstraightline << " " << i;
				}
				else if (counter != 1 && counter != wordWrapLimit) {
					if (i != deadSwitch) {
						std::cout << i;
					}
					else {
						for (int k{ 0 }; k < (wordWrapLimit - counter + 1); k++) {
							std::cout << " ";
						}
						std::cout << " " << (char)lightstraightline << std::endl;
					}
				}
				else if (counter == wordWrapLimit) {
					std::cout << i << " " << (char)lightstraightline << std::endl;
					counter = 0;
				}
				counter++;
			}
			std::cout << (char)thintothickcornerbtlf << std::string(wordWrapLimit + 2, (char)across) << (char)thicktothincornerbtrt << std::endl;
		}
		else {
			std::cout
				<< (char)thintothickcornertplf << std::string(input.length() + 2, (char)across) << (char)thicktothincornertprt << std::endl
				<< (char)lightstraightline << " " << input << " " << (char)lightstraightline << std::endl
				<< (char)thintothickcornerbtlf << std::string(input.length() + 2, (char)across) << (char)thicktothincornerbtrt << std::endl;
		}
		break;
	}
	}
}
/// <summary>
/// Creates a border around the input, depending on the style.
/// </summary>
/// <param name="input">- The input parameter</param>
/// <param name="style">- 0 double line, 1 single line, 2 bold line, 3 thick sides, 4 thick top and bottom</param>
/// <param name="wordWrap">- Defines whether the text is wrapped</param>
/// <param name="wordWrapLimit">- Defines how much the text is wrapped by</param>
void GUI::MakeBox(std::vector<std::string> input, int style, bool wordWrap, int wordWrapLimit)
{
	std::string inputString{};
	int counter{};
	for (std::string i : input) {
		if (counter < input.size()) {
			inputString += i + ", ";
		}
		else {
			inputString += i;
		}
	}
	MakeBox(inputString, style, wordWrap, wordWrapLimit);
}
/// <summary>
/// Creates a border around the input, depending on the style.
/// </summary>
/// <param name="input">- The input parameter</param>
/// <param name="style">- 0 double line, 1 single line, 2 bold line, 3 thick sides, 4 thick top and bottom</param>
/// <param name="wordWrap">- Defines whether the text is wrapped</param>
/// <param name="wordWrapLimit">- Defines how much the text is wrapped by</param>
void GUI::MakeBox(std::vector<int> input, int style, bool wordWrap, int wordWrapLimit)
{
	std::vector<std::string> inputStrings{};
	for (int i : input) {
		inputStrings.push_back(std::to_string(i));
	}
	MakeBox(inputStrings, style, wordWrap, wordWrapLimit);
}
/// <summary>
/// Creates a border around the input, depending on the style.
/// </summary>
/// <param name="input">- The input parameter</param>
/// <param name="style">- 0 double line, 1 single line, 2 bold line, 3 thick sides, 4 thick top and bottom</param>
/// <param name="wordWrap">- Defines whether the text is wrapped</param>
/// <param name="wordWrapLimit">- Defines how much the text is wrapped by</param>
void GUI::MakeBox(std::vector<float> input, int style, bool wordWrap, int wordWrapLimit)
{
	std::vector<std::string> inputStrings{};
	for (float i : input) {
		inputStrings.push_back(std::to_string(i));
	}
	MakeBox(inputStrings, style, wordWrap, wordWrapLimit);
}

void GUI::GenerateMenu(std::string header, std::vector<std::string> menuOptions, std::string footer)
{
	int longestLen{};
	longestLen = header.length();
	for (std::string i : menuOptions) {
		if (i.length() > longestLen) {
			longestLen = i.length();
		}
	}
	if ((longestLen % 2) == 1) {
		longestLen++;
	}
	if ((header.length() % 2) == 1) {
		header = " " + header;
	}

	std::cout
		<< (char)cornertplf << std::string(longestLen + 2, (char)across) << (char)cornertprt << std::endl
		<< (char)straightline << " " << std::string((longestLen - header.length()) / 2, ' ') << header << std::string((longestLen - header.length()) / 2, ' ') << " " << (char)straightline << std::endl
		<< (char)thicktothinleftintersection << std::string(longestLen + 2, (char)lightacross) << (char)thintothickrightintersection << std::endl;
	
	for (std::string i : menuOptions) {
		std::cout << (char)straightline << " " << i << std::string(longestLen - i.length(), ' ') << " " << (char)straightline << std::endl;
	}
	std::cout << (char)cornerbtlf << std::string(longestLen + 2, (char)across) << (char)cornerbtrt << std::endl << std::endl;
}

void GUI::GenerateGrid(std::vector<std::string> objects, int style, int height, int width)
{

}


