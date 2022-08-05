#include "menu.h"

Menu::Menu(std::string text, char trigger)
{
	this->text = text;
	this->trigger = trigger;
}

std::string Menu::get_text()
{
	return this->text;
}

int Menu::get_start_x()
{
	return this->start_x;
}

char Menu::get_trigger()
{
	return this->trigger;
}

void Menu::set_text(std::string input)
{
	this->text = input;
}

void Menu::set_start_x(int input)
{
	this->start_x = input;
}

void Menu::set_trigger(char input)
{
	this->trigger = input;
}
