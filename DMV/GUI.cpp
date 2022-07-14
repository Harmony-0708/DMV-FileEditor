#include "GUI.h"


/// <summary>
/// Acts the same as HLib::WordWrap but places a line around each row
/// </summary>
/// <param name="wrapLimit">- Wrap Limit</param>
/// <param name="inputString">- String to be wrapped</param>
void GUI::GUIWordWrap(int wrapLimit, std::string inputString)
{
	int counter{};
	bool spaceStart{false};
	for (char i : inputString) {
		if (counter == 0) {
			if (i != ' ') {
				std::cout << (char)straightline << " ";
				spaceStart = false;
			}
			else {
				std::cout << (char)straightline;
				spaceStart = true;
			}
		}
		if (counter < wrapLimit) {
			std::cout << i;
			counter++;
		}
		if (i == ' ' || i == ',' || i == '.' || i == '!' || i == '?' || i == ':') {
			bool check{false};
			std::string tempString{};
			for (int k{ 0 }; k < 10; k++) {
				if (inputString[i + k] == ' ') {
					check = true;
					break;
				}
				tempString += inputString[i + k];
			}
			if (!check) {
				if (spaceStart) {
					std::cout << std::string(wrapLimit - counter, ' ') << "  " << (char)straightline << std::endl;
				}
				else {
					std::cout << std::string(wrapLimit - counter, ' ') << " " << (char)straightline << std::endl;
				}
				counter = 0;
			}
			else if (tempString.length() >=  (wrapLimit - counter)) {
				if (spaceStart) {
					std::cout << std::string(wrapLimit - counter, ' ') << "  " << (char)straightline << std::endl;
				}
				else {
					std::cout << std::string(wrapLimit - counter, ' ') << " " << (char)straightline << std::endl;
				}
				counter = 0;
			}
		}
	}
	if (spaceStart) {
		std::cout << std::string(wrapLimit-counter, ' ') << "  " << (char)straightline << std::endl;
	}
	else {
		std::cout << std::string(wrapLimit - counter, ' ') << " " << (char)straightline << std::endl;
	}
	
}

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

/// <summary>
/// Generates a menu using a header and a set of menu options, footer is optional
/// </summary>
/// <param name="header">- Header of the menu</param>
/// <param name="menuOptions">- All menu options</param>
/// <param name="footer">- Optional footer at the bottom</param>
/// <param name="multiCol">- Optional Allows for multiple options a column</param>
/// <param name="cols">- Optional Amount of columns for multicolumn</param>
void GUI::GenerateMenu(std::string header, std::vector<std::string> menuOptions, std::string footer, bool multiCol, int cols)
{
	if (menuOptions.size() != 0) {
		if (cols == 1) {
			multiCol = false;
		}
		if (!multiCol) {
			int longestLen{};
			bool longCheck{};
			if (header.length() > footer.length()) { longestLen = header.length(); }
			else { longestLen = footer.length(); }
			longestLen = HLib::FindLongest(menuOptions, longestLen);
			if (longestLen > 102) {
				longestLen = 100;
				longCheck = true;
			}
			if ((longestLen % 2 != 1) || (header.length() % 2 != 1)) {
				if ((longestLen % 2) == 1) {
					longestLen++;
				}
				if ((header.length() % 2) == 1) {
					header = " " + header;
				}
			}

			if ((footer.length() % 2) == 1) {
				footer = " " + footer;
			}
			std::cout
				<< (char)cornertplf << std::string(longestLen + 2, (char)across) << (char)cornertprt << std::endl
				<< (char)straightline << " " << std::string((longestLen - header.length()) / 2, ' ') << header << std::string((longestLen - header.length()) / 2, ' ') << " " << (char)straightline << std::endl
				<< (char)thicktothinleftintersection << std::string(longestLen + 2, (char)lightacross) << (char)thintothickrightintersection << std::endl;
			for (std::string i : menuOptions) {
				if (longCheck) {
					GUIWordWrap(100, i);
				}
				else {
					std::cout << (char)straightline << " " << i << std::string(longestLen - i.length(), ' ') << " " << (char)straightline << std::endl;
				}
			}
			if (footer != "") {
				std::cout
					<< (char)thicktothinleftintersection << std::string(longestLen + 2, (char)lightacross) << (char)thintothickrightintersection << std::endl
					<< (char)straightline << " " << std::string((longestLen - footer.length()) / 2, ' ') << footer << std::string((longestLen - footer.length()) / 2, ' ') << " " << (char)straightline << std::endl;
			}
			std::cout << (char)cornerbtlf << std::string(longestLen + 2, (char)across) << (char)cornerbtrt << std::endl << std::endl;
		}
		else {
			int longestLen{};
			int trueLongest{};
			bool longCheck{};
			trueLongest = HLib::FindLongest(menuOptions) + 3;
			longestLen = trueLongest * cols + (cols - 1) - 2;
			if ((longestLen % 2) == 1) {
				longestLen++;
			}
			if ((header.length() % 2) == 1) {
				header = " " + header;
			}
			if ((footer.length() % 2) == 1) {
				footer = " " + footer;
			}

			std::cout
				<< (char)cornertplf << std::string(longestLen, (char)across) << (char)cornertprt << std::endl
				<< (char)straightline << std::string((longestLen - header.length()) / 2, ' ') << header << std::string((longestLen - header.length()) / 2, ' ') << (char)straightline << std::endl
				<< (char)thicktothinleftintersection << std::string(longestLen, (char)lightacross) << (char)thintothickrightintersection << std::endl;

			int colIndex{ 0 };
			bool endCheck{ false };
			for (std::string i : menuOptions) {
				if (colIndex == 0) {
					std::cout << (char)straightline << " " << i << std::string((trueLongest - 2) - i.length(), ' ') << " " << (char)lightstraightline;
					colIndex++;
					endCheck = false;
				}
				else if (colIndex + 1 == cols) {
					std::cout << " " << i << std::string((trueLongest - 2) - i.length(), ' ') << (char)straightline << std::endl;
					colIndex = 0;
					endCheck = true;
				}
				else {
					std::cout << " " << i << std::string(((trueLongest - 2) - i.length()), ' ') << " " << (char)lightstraightline;
					colIndex++;
					endCheck = false;
				}
			}
			while (colIndex != cols && endCheck != true) {
				if (colIndex == 0) {
					std::cout << (char)straightline;
					colIndex++;
				}
				if (colIndex + 1 == cols) {
					std::cout << " " << std::string((trueLongest - 2), ' ') << (char)straightline << std::endl;
					colIndex = cols;
				}
				else {
					std::cout << " " << std::string((trueLongest - 2), ' ') << " " << (char)lightstraightline;
					colIndex++;
				}
			}
			if (footer != "") {
				std::cout
					<< (char)thicktothinleftintersection << std::string(longestLen, (char)lightacross) << (char)thintothickrightintersection << std::endl
					<< (char)straightline << std::string((longestLen - footer.length()) / 2, ' ') << footer << std::string((longestLen - footer.length()) / 2, ' ') << (char)straightline << std::endl;
			}
			std::cout << (char)cornerbtlf << std::string(longestLen, (char)across) << (char)cornerbtrt << std::endl << std::endl;
		}
	}
}


/// <summary>
/// Generates a grid pased on the given objects vector, if given a height or width it will make it a specific height and width
/// </summary>
/// <param name="objects">- Set of objects to display</param>
/// <param name="height">- Optional height of grid</param>
/// <param name="width">- Optional width of grid</param>
void GUI::GenerateGrid(std::vector<std::string> objects, int height, int width)
{
	if (height == 0 && width == 0) {
		width = objects.size();
		height = 1;
		std::vector<std::string> elements{};
		int amntElements{};
		int heightCounter{};
		if (objects.size() > (height * width)) {
			amntElements = objects.size();
		}
		else {
			amntElements = (height * width);
		}
		for (int k{ 0 }; k < (amntElements - objects.size()); k++) {
			elements.push_back("");
		}
		for (int i{ 1 }; i <= amntElements; i++) {
			if (objects.size() != 0) {
				elements.push_back(objects.back());
				objects.pop_back();
			}
		}
		int maxWidth{ HLib::FindLongest(elements) };
		//  Row          Column
		std::vector<std::vector<std::string>> rows{};
		for (int i{ 0 }; i < height; i++) {
			std::vector<std::string> col{};
			for (int k{ 0 }; k < width; k++) {
				col.push_back(elements.back());
				elements.pop_back();
			}
			rows.push_back(col);
		}
		if (maxWidth % 2 == 1) {
			maxWidth += 1;
		}
		std::cout << (char)cornertplf;
		for (int i{ 0 }; i < width; i++) {
			if (i + 1 != width) {
				std::cout << std::string(maxWidth + 2, (char)across) << (char)thicktothinupperintersection;
			}
			else {
				std::cout << std::string(maxWidth + 2, (char)across);
			}
		}
		std::cout << (char)cornertprt << std::endl;
		for (std::vector<std::string> i : rows) {
			std::cout << (char)straightline << " ";
			for (int k{ 0 }; k < i.size(); k++) {
				std::string buffer{};
				if (i[k].length() != maxWidth) {
					buffer = std::string(maxWidth - i[k].length(), ' ');
				}
				std::cout << i[k] << buffer;
				if (k + 1 == i.size()) {
					std::cout << " ";
				}
				else {
					std::cout << " " << (char)lightstraightline << " ";
				}
			}
			std::cout << (char)straightline << std::endl;
			if (heightCounter + 1 != height) {
				std::cout << (char)thicktothinleftintersection;
				for (int j{ 0 }; j < width; j++) {
					std::cout << std::string(maxWidth + 2, (char)lightacross);
					if (j + 1 != width) {
						std::cout << (char)lightfullintersection;
					}
				}
				std::cout << (char)thintothickrightintersection << std::endl;
			}
			else {
				std::cout << (char)cornerbtlf;
				for (int i{ 0 }; i < width; i++) {
					if (i + 1 != width) {
						std::cout << std::string(maxWidth + 2, (char)across) << (char)thicktothinbottomintersection;
					}
					else {
						std::cout << std::string(maxWidth + 2, (char)across);
					}
				}
				std::cout << (char)cornerbtrt << std::endl;
			}
			heightCounter++;
		}
	}
	else if (height != 0 && width == 0) {
		width = std::ceil(objects.size() / (float)height);
		std::vector<std::string> elements{};
		int amntElements{};
		int heightCounter{};
		if (objects.size() > (height * width)) {
			amntElements = objects.size();
		}
		else {
			amntElements = (height * width);
		}
		for (int k{ 0 }; k < (amntElements - objects.size()); k++) {
			elements.push_back("");
		}
		for (int i{ 1 }; i <= amntElements; i++) {
			if (objects.size() != 0) {
				elements.push_back(objects.back());
				objects.pop_back();
			}
		}
		int maxWidth{ HLib::FindLongest(elements) };
		//  Row          Column
		std::vector<std::vector<std::string>> rows{};
		for (int i{ 0 }; i < height; i++) {
			std::vector<std::string> col{};
			for (int k{ 0 }; k < width; k++) {
				col.push_back(elements.back());
				elements.pop_back();
			}
			rows.push_back(col);
		}
		if (maxWidth % 2 == 1) {
			maxWidth += 1;
		}
		std::cout << (char)cornertplf;
		for (int i{ 0 }; i < width; i++) {
			if (i + 1 != width) {
				std::cout << std::string(maxWidth + 2, (char)across) << (char)thicktothinupperintersection;
			}
			else {
				std::cout << std::string(maxWidth + 2, (char)across);
			}
		}
		std::cout << (char)cornertprt << std::endl;
		for (std::vector<std::string> i : rows) {
			std::cout << (char)straightline << " ";
			for (int k{ 0 }; k < i.size(); k++) {
				std::string buffer{};
				if (i[k].length() != maxWidth) {
					buffer = std::string(maxWidth - i[k].length(), ' ');
				}
				std::cout << i[k] << buffer;
				if (k + 1 == i.size()) {
					std::cout << " ";
				}
				else {
					std::cout << " " << (char)lightstraightline << " ";
				}
			}
			std::cout << (char)straightline << std::endl;
			if (heightCounter + 1 != height) {
				std::cout << (char)thicktothinleftintersection;
				for (int j{ 0 }; j < width; j++) {
					std::cout << std::string(maxWidth + 2, (char)lightacross);
					if (j + 1 != width) {
						std::cout << (char)lightfullintersection;
					}
				}
				std::cout << (char)thintothickrightintersection << std::endl;
			}
			else {
				std::cout << (char)cornerbtlf;
				for (int i{ 0 }; i < width; i++) {
					if (i + 1 != width) {
						std::cout << std::string(maxWidth + 2, (char)across) << (char)thicktothinbottomintersection;
					}
					else {
						std::cout << std::string(maxWidth + 2, (char)across);
					}
				}
				std::cout << (char)cornerbtrt << std::endl;
			}
			heightCounter++;
		}
	}
	else if (height == 0 && width != 0) {
		height = std::ceil(objects.size() / (float)width);
		std::vector<std::string> elements{};
		int amntElements{};
		int heightCounter{};
		if (objects.size() > (height * width)) {
			amntElements = objects.size();
		}
		else {
			amntElements = (height * width);
		}
		for (int k{ 0 }; k < (amntElements - objects.size()); k++) {
			elements.push_back("");
		}
		for (int i{ 1 }; i <= amntElements; i++) {
			if (objects.size() != 0) {
				elements.push_back(objects.back());
				objects.pop_back();
			}
		}
		int maxWidth{ HLib::FindLongest(elements) };
		//  Row          Column
		std::vector<std::vector<std::string>> rows{};
		for (int i{ 0 }; i < height; i++) {
			std::vector<std::string> col{};
			for (int k{ 0 }; k < width; k++) {
				col.push_back(elements.back());
				elements.pop_back();
			}
			rows.push_back(col);
		}
		if (maxWidth % 2 == 1) {
			maxWidth += 1;
		}
		std::cout << (char)cornertplf;
		for (int i{ 0 }; i < width; i++) {
			if (i + 1 != width) {
				std::cout << std::string(maxWidth + 2, (char)across) << (char)thicktothinupperintersection;
			}
			else {
				std::cout << std::string(maxWidth + 2, (char)across);
			}
		}
		std::cout << (char)cornertprt << std::endl;
		for (std::vector<std::string> i : rows) {
			std::cout << (char)straightline << " ";
			for (int k{ 0 }; k < i.size(); k++) {
				std::string buffer{};
				if (i[k].length() != maxWidth) {
					buffer = std::string(maxWidth - i[k].length(), ' ');
				}
				std::cout << i[k] << buffer;
				if (k + 1 == i.size()) {
					std::cout << " ";
				}
				else {
					std::cout << " " << (char)lightstraightline << " ";
				}
			}
			std::cout << (char)straightline << std::endl;
			if (heightCounter + 1 != height) {
				std::cout << (char)thicktothinleftintersection;
				for (int j{ 0 }; j < width; j++) {
					std::cout << std::string(maxWidth + 2, (char)lightacross);
					if (j + 1 != width) {
						std::cout << (char)lightfullintersection;
					}
				}
				std::cout << (char)thintothickrightintersection << std::endl;
			}
			else {
				std::cout << (char)cornerbtlf;
				for (int i{ 0 }; i < width; i++) {
					if (i + 1 != width) {
						std::cout << std::string(maxWidth + 2, (char)across) << (char)thicktothinbottomintersection;
					}
					else {
						std::cout << std::string(maxWidth + 2, (char)across);
					}
				}
				std::cout << (char)cornerbtrt << std::endl;
			}
			heightCounter++;
		}
	}
	else {
		std::vector<std::string> elements{};
		int amntElements{};
		int heightCounter{};
		if (objects.size() > (height * width)) {
			amntElements = objects.size();
		}
		else {
			amntElements = (height * width);
		}
		for (int k{ 0 }; k < (amntElements - objects.size()); k++) {
				elements.push_back("");
			}
		for (int i{ 1 }; i <= amntElements;i++) {
			if (objects.size() != 0) {
				elements.push_back(objects.back());
				objects.pop_back();
			}
		}
		int maxWidth{ HLib::FindLongest(elements) };
		//  Row          Column
		std::vector<std::vector<std::string>> rows{};
		for (int i{ 0 }; i < height; i++) {
			std::vector<std::string> col{};
			for (int k{ 0 }; k < width; k++) {
				col.push_back(elements.back());
				elements.pop_back();
			}
			rows.push_back(col);
		}
		if (maxWidth % 2 == 1) {
			maxWidth += 1;
		}
		std::cout << (char)cornertplf;
		for (int i{ 0 }; i < width; i++) {
			if (i + 1 != width) {
				std::cout << std::string(maxWidth + 2, (char)across) << (char)thicktothinupperintersection;
			}
			else {
				std::cout << std::string(maxWidth + 2, (char)across);
			}
		}
		std::cout << (char)cornertprt << std::endl;
 		for (std::vector<std::string> i : rows) {
			std::cout << (char)straightline << " ";
			for (int k{ 0 }; k < i.size();k++) {
				std::string buffer{};
				if (i[k].length() != maxWidth) {
					buffer = std::string(maxWidth - i[k].length(),' ');
				}
				std::cout << i[k] << buffer;
				if (k + 1 == i.size()) {
					std::cout << " ";
				}
				else {
					std::cout << " " << (char)lightstraightline << " ";
				}
			}
			std::cout << (char)straightline << std::endl;
			if (heightCounter + 1 != height) {
				std::cout << (char)thicktothinleftintersection;
				for (int j{ 0 }; j < width; j++) {
					std::cout << std::string(maxWidth + 2, (char)lightacross);
					if (j + 1 != width) {
						std::cout << (char)lightfullintersection;
					}
				}
				std::cout << (char)thintothickrightintersection << std::endl;
			}
			else {
				std::cout << (char)cornerbtlf;
				for (int i{ 0 }; i < width; i++) {
					if (i + 1 != width) {
						std::cout << std::string(maxWidth + 2, (char)across) << (char)thicktothinbottomintersection;
					}
					else {
						std::cout << std::string(maxWidth + 2, (char)across);
					}
				}
				std::cout << (char)cornerbtrt << std::endl;
			}
			heightCounter++;
		}
	}
}


