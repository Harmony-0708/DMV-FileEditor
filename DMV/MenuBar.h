#pragma once
#include <string>
#include <curses.h>
#include "menu.h"

class MenuBar
{
private:
	WINDOW* win;
	Menu* menus;
	int num_menus{};;
	int selected_menu{};

public:
	MenuBar(WINDOW* win, Menu* menus, int num_menus);

	void draw();
	void handleTrigger(char trigger);
};

