#pragma once
#include "ConsoleUtils.h"
#include "Map.h"
#include <stdlib.h>
#include <time.h>

class Enemy
{
private:
	COORD position;
	COORD direction;
	char character = 'X';
	ConsoleUtils::CONSOLE_COLOR  foreground = ConsoleUtils::CONSOLE_COLOR::DARK_GREEN;
	ConsoleUtils::CONSOLE_COLOR  background = ConsoleUtils::CONSOLE_COLOR::WHITE;
	void RandomDirection();
	

public:
	Enemy();
	Enemy(COORD _spawn);

	void Draw();
	void Update(Map* _map);

};

