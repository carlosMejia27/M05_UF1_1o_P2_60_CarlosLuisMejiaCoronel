#include "PLAYER.h"

PLAYER::PLAYER(COORD _spawn)
{
	spawn = _spawn;
	position = _spawn;
	direction = { 0,0 };
}

void PLAYER::Update(Map* _map, USER_INPUTS input, std::vector<Enemy>* enemies)
{
    COORD newPosition = position;
   
    switch (input)
    {
    case UP:
        newPosition.Y--;
        break;
    case DOWN:
        newPosition.Y++;
        break;
    case RIGHT:
        newPosition.X++;
        break;
    case LEFT:
        newPosition.X--;
        break;
   
    }
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

    switch (_map->GetTile(newPosition.X,newPosition.Y))
    {
    case Map::MAP_TILES::MAP_WALL:
        newPosition.X = position.X;
        newPosition.Y = position.Y;
        break;
    case Map::MAP_TILES::MAP_POINT:
        _map->points--;
        points++;
        _map->SetTile(newPosition.X, newPosition.Y, Map::MAP_TILES::MAP_EMPTY);
        break;
    case Map::MAP_TILES::MAP_POWERUP:
      points += 25;
        ;
        for (size_t i = 0; i < enemies->size(); i++)
        {
            enemies->at(i).PoweUpPicked();
         //   (*enemies)[i].PoweUpPicked(); asi es una cuando trabajo por referencias
        }
        _map->SetTile(newPosition.X, newPosition.Y, Map::MAP_TILES::MAP_EMPTY);
        break;
    }

    position = newPosition;


}


void PLAYER::Draw()
{
	ConsoleUtils::Console_SetPos(position);
	ConsoleUtils::Console_SetColor(foreground, background);
	std::cout << character;
}

void PLAYER::kill()
{
    ConsoleUtils::Console_SetColor(ConsoleUtils::CONSOLE_COLOR::RED);
    foreground = ConsoleUtils::CONSOLE_COLOR::BLACK;
    std::cout << "Has Perdido!" << std::endl;
}


