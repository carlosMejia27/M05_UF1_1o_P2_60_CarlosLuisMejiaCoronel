#include "Enemy.h"

Enemy::Enemy()
{
	position = { 10,5 };
	direction = { 0,0 };
}

Enemy::Enemy(COORD _spawn)
{
	position = _spawn;
	direction = { 0,0 };
}

void Enemy::Draw()
{

	ConsoleUtils::Console_SetPos(position);
	ConsoleUtils::Console_SetColor(foreground,background);
	std::cout << character;

}
