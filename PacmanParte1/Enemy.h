#pragma once
#include "ConsoleUtils.h"

class Enemy
{
private:
	COORD position;
	COORD direction;
	char character = 'X';
	ConsoleUtils::CONSOLE_COLOR  foreground = ConsoleUtils::CONSOLE_COLOR::DARK_GREEN;
	ConsoleUtils::CONSOLE_COLOR  background = ConsoleUtils::CONSOLE_COLOR::WHITE;
	

public:
	Enemy();
	Enemy(COORD _spawn);

	void Draw();
};

