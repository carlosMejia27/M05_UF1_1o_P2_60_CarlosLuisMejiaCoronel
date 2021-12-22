#include "Enemy.h"

void Enemy::RandomDirection()
{
	direction = { 0,0 }; /// movimiento del enemigo ramdom
	int random = rand() % 4;

	switch (random)
	{
	case 0:
		direction.X = 1;
		break;
	case 1:
		direction.X = -1;
		break;
	case 2:
		direction.Y = 1;
		break;
	case 3:
		direction.Y = -1;
		break;
	default:
		break;
	}
}

Enemy::Enemy()
{
	spawn = { 0,0 };
	position = spawn;
	direction = { 0,0 };
}

Enemy::Enemy(COORD _spawn)
{
	spawn = _spawn;
	position = _spawn;
	direction = { 0,0};
}

void Enemy::Draw()
{

	ConsoleUtils::Console_SetPos(position);
	ConsoleUtils::Console_SetColor(foreground,background);
	std::cout << character;

}

void Enemy::PoweUpPicked()
{

	power_countdown = TimeManager::getInstance().time+powerup_countdown_time;
}

Enemy::ENEMY_STATE Enemy::Update(Map* _map, COORD _player)
{
	//power_countdown += TimeManager::getInstance().deltaTime; que tarda cada fotograma
	
	RandomDirection();
	COORD newPosition = position;
	newPosition.X += direction.X; // actualizo la posicion xy y
	newPosition.Y += direction.Y;

	// teletransporteee
	if (newPosition.X < 0)
	{
		newPosition.X = _map->Width - 1;
	}
	newPosition.X %= _map->Width;
	if (newPosition.Y < 0)
	{
		newPosition.Y = _map->Height - 1;
	}
	newPosition.Y %= _map->Height;

	switch (_map->GetTile(newPosition.X, newPosition.Y))// que si toco un muro me haga una posicion atras
	{
	case Map::MAP_TILES::MAP_WALL:
		newPosition = position;
		
		break;
		
	}
	ENEMY_STATE state= ENEMY_STATE::ENEMY_NONE;
	position = newPosition;
	if (position.X==_player.X && position.Y == _player.Y) /// hago que el fantasma aparesca al inicio
	{
		if (power_countdown <= TimeManager::getInstance().time)
		{
			state = ENEMY_STATE::ENEMY_DEAD;
		}
		else
		{
			position = spawn;
			state = ENEMY_STATE::ENEMY_KILLED;
		}
		
	}
	if (power_countdown<=TimeManager::getInstance().time)
	{
		foreground = foreground_attack;
	}
	else
	{
		foreground = oreground_powerUp;
	}

	return state;
}
