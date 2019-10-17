#include "GameSystem.h"
#include<conio.h>
#include<iostream>

//using namespace std;


//To Set Up The Game
GameSystem::GameSystem(string LevelFileName)
{
	_Player.init(1, 100, 10, 10, 0);

	_Level.LoadLevel(LevelFileName, _Player);
	_Level.PrintLevel();
	system("PAUSE");
}

void GameSystem::PlayGame()
{
	bool isDone = false;

	while (isDone == false)
	{
		_Level.PrintLevel();
		_Player.DispStats();
		PlayerMove();
		_Level.UpdateEnemyPos(_Player);
	}
}


void GameSystem::PlayerMove()
{
	char Input;
	cout<<"Enter a Move Command (W/A/S/D): ";
	Input = _getch();

	_Level.MovePlayer(Input, _Player);
}