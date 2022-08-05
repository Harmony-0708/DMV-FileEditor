#pragma once
#include <string>
#include <curses.h>

class Menu
{
private:
	std::string text;
	std::string* items;
	char trigger;
	int start_x;
	int num_items;
	int selected_item;

public:
	Menu(std::string text, char trigger);

	//gets
	std::string get_text();
	std::string get_items();
	char get_trigger();
	int get_start_x();
	int get_num_items();
	int selected_item();

	//sets
	void set_text(std::string input);
	void set_trigger(char input);
	void set_start_x(int input);

};

