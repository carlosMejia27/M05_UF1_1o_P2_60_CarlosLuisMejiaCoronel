#pragma once
#include "ConsoleUtils.h"
#include "Map.h"
#include "TimeManager.h"
#include <stdlib.h>
#include <time.h>

class Enemy
{
private:
	COORD spawn;
	COORD position;
	COORD direction;
	char character = 'X';
	float power_countdown = 0;
	const float powerup_countdown_time = 15;
	ConsoleUtils::CONSOLE_COLOR  foreground = ConsoleUtils::CONSOLE_COLOR::RED;
	ConsoleUtils::CONSOLE_COLOR  background = ConsoleUtils::CONSOLE_COLOR::BLACK;

	ConsoleUtils::CONSOLE_COLOR  foreground_attack = ConsoleUtils::CONSOLE_COLOR::RED;
	ConsoleUtils::CONSOLE_COLOR  oreground_powerUp = ConsoleUtils::CONSOLE_COLOR::DARK_YELLOW;
	void RandomDirection();
	

public:
	enum ENEMY_STATE{ENEMY_NONE,ENEMY_KILLED,ENEMY_DEAD};
	Enemy();
	Enemy(COORD _spawn);
	void Draw();
	void PoweUpPicked();
	ENEMY_STATE Update(Map* _map, COORD _player);
	

};

