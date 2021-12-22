#pragma once
#include "ConsoleUtils.h"
#include "Map.h"
#include "Enemy.h"
#include <vector>

enum USER_INPUTS { NONE, UP, DOWN, RIGHT, LEFT, QUIT };
class PLAYER
{
	private:
	COORD spawn;
	COORD direction;
	char character = 'O';
	//ConsoleUtils::CONSOLE_COLOR  foreground = ConsoleUtils::CONSOLE_COLOR::YELLOW; // o
	ConsoleUtils::CONSOLE_COLOR  background = ConsoleUtils::CONSOLE_COLOR::BLACK; // fondo

public:

	PLAYER(COORD _spawn);
	void Update(Map* _map, USER_INPUTS input, std::vector<Enemy>* enemies);
	void Draw();
	void kill();
	int points = 0;
	COORD position;
	ConsoleUtils::CONSOLE_COLOR  foreground = ConsoleUtils::CONSOLE_COLOR::YELLOW; // o
};

