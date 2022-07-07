#include "GUI.h"

void GUI::MakeBox(int input, int style)
{
	
	switch (style) {
	case 0: {
		std::cout
			<< (char)cornertplf << std::string(3, (char)across) << (char)cornertprt << std::endl
			<< (char)straightline << " " << input << " " << (char)straightline << std::endl
			<< (char)cornerbtlf << std::string(3, (char)across) << (char)cornerbtrt << std::endl;
		break;
	}
	case 1: {



		break;
	}
	case 2: {



		break;
	}
	case 3: {



		break;
	}
	case 4: {



		break;
	}
	}

}

void GUI::MakeBox(std::string input, int style)
{
	switch (style) {
	case 0: {



		break;
	}
	case 1: {



		break;
	}
	case 2: {



		break;
	}
	case 3: {



		break;
	}
	case 4: {



		break;
	}
	}
}

void GUI::MakeBox(std::vector<std::string> input, int style)
{
	switch (style) {
	case 0: {



		break;
	}
	case 1: {



		break;
	}
	case 2: {



		break;
	}
	case 3: {



		break;
	}
	case 4: {



		break;
	}
	}
}

void GUI::MakeBox(std::vector<int> input, int style)
{
	switch (style) {
	case 0: {



		break;
	}
	case 1: {



		break;
	}
	case 2: {



		break;
	}
	case 3: {



		break;
	}
	case 4: {



		break;
	}
	}
}

void GUI::MakeBox(std::vector<float> input, int style)
{
	switch (style) {
	case 0: {



		break;
	}
	case 1: {



		break;
	}
	case 2: {



		break;
	}
	case 3: {



		break;
	}
	case 4: {



		break;
	}
	}
}
