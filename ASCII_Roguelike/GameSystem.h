#pragma once

#include"Player.h"
#include"Level.h"
#include<string>

using namespace std;

class GameSystem
{
public:
	GameSystem(string LevelFileName);

	void PlayGame();
	void PlayerMove();

private:
	Player _Player;
	Level _Level;
};