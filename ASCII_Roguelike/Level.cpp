#include "Level.h"
#include <iostream>
#include <fstream>

using namespace std;

Level::Level()
{
	
}

void Level::LoadLevel(string FileName, Player &_Player)
{
	//To Load The Level
	ifstream File;
	File.open(FileName);
	if (File.fail())
	{
		perror(FileName.c_str());
		system("PAUSE");
		exit(0);
	}

	string Line;

	while (getline(File, Line))
	{
		_LevelData.push_back(Line);
	}

	File.close();
	
	//Process The Level

	char Tile;

	for (int i = 0; i < _LevelData.size(); i++)
	{
		for (int j = 0; j < _LevelData[i].size(); j++)
		{
			Tile = _LevelData[i][j];

			switch (Tile)
			{
			case '@'://Player
				_Player.SetPosition(j, i);
				break;
			case 'S'://Snake
				_Enemies.push_back(Enemy("Snake", Tile, 2, 5, 2, 30, 30));
				_Enemies.back().SetPosition(j, i);
				break;
			case 'D'://Dragon
				_Enemies.push_back(Enemy("Dragon", Tile, 100, 4000, 30000, 10000, 10000000));
				_Enemies.back().SetPosition(j, i);
				break;
			case 'g'://Goblin
				_Enemies.push_back(Enemy("Goblin", Tile, 4, 10, 5, 35, 50));
				_Enemies.back().SetPosition(j, i);
				break;
			}
		}
	}

}

void Level::PrintLevel()
{
	//cout<<string(100, '\n');
	system("cls");

	for (int i = 0; i < _LevelData.size(); i++)
	{
		cout<<_LevelData[i]<<endl;
	}
	cout<<endl;
}

void Level::MovePlayer(char Input, Player &_Player)
{
	int PlayerX;
	int PlayerY;

	_Player.GetPosition(PlayerX, PlayerY);

	switch (Input)
	{

	case 'w'://Up
	case 'W':
		ProcessPlayerMove(_Player, PlayerX, PlayerY - 1);
		break;
	case 'a'://Left
	case 'A':
		ProcessPlayerMove(_Player, PlayerX - 1 , PlayerY);
		break;
	case 's'://Down
	case 'S':
		ProcessPlayerMove(_Player, PlayerX, PlayerY + 1);
		break;
	case 'd'://Right
	case 'D':
		ProcessPlayerMove(_Player, PlayerX + 1, PlayerY);
		break;
	default:
		cout<<"Invalid Input\n";
		system("PAUSE");
		break;
	}
}

void Level::UpdateEnemyPos(Player &_Player)
{
	char RandMove;
	int PlayerX;
	int PlayerY;
	int EnemyX;
	int EnemyY;

	_Player.GetPosition(PlayerX, PlayerY);
	for (int i = 0; i < _Enemies.size(); i++)
	{
		_Enemies[i].GetPosition(EnemyX, EnemyY);
		RandMove = _Enemies[i].EnemyRandMove(PlayerX, PlayerY);
		switch (RandMove)
		{
	
		case 'w'://Up
			ProcessEnemyMove(_Player, i, EnemyX, EnemyY - 1);
			break;
		case 'a'://Left
			ProcessEnemyMove(_Player, i, EnemyX - 1 , EnemyY);
			break;
		case 's'://Down
			ProcessEnemyMove(_Player, i, EnemyX, EnemyY + 1);
			break;
		case 'd'://Right
			ProcessEnemyMove(_Player, i, EnemyX + 1, EnemyY);
			break;
	}
	}
}

char Level::GetTile(int X, int Y)
{
	return _LevelData[Y][X];
}

void Level::SetTile(int X, int Y, char Tile)
{
	_LevelData[Y][X] = Tile;
}

void Level::ProcessPlayerMove(Player &_Player, int TargetX, int TargetY)
{
	int PlayerX;
	int PlayerY;

	_Player.GetPosition(PlayerX, PlayerY);
	char MoveTile= GetTile(TargetX, TargetY);
	switch (MoveTile)
		{
		case '#':
			cout<<"You Ran into a Wall\n";
			system("PAUSE");
			break;
		case '.':
			_Player.SetPosition(TargetX, TargetY);
			SetTile(PlayerX, PlayerY, '.');
			SetTile(TargetX, TargetY, '@');
			break;
		case 'S':
		case 'D':
		case 'g':
			BattleEnemy(_Player, TargetX, TargetY);
				break;

		default:
			break;
		}
}

void Level::ProcessEnemyMove(Player &_Player, int EnemyIndex, int TargetX, int TargetY)
{
	int PlayerX;
	int PlayerY;
	int EnemyX;
	int EnemyY;

	_Enemies[EnemyIndex].GetPosition(EnemyX, EnemyY);

	_Player.GetPosition(PlayerX, PlayerY);
	char MoveTile= GetTile(TargetX, TargetY);
	switch (MoveTile)
		{
		case '.':
			_Enemies[EnemyIndex].SetPosition(TargetX, TargetY);
			SetTile(EnemyX, EnemyY, '.');
			SetTile(TargetX, TargetY, _Enemies[EnemyIndex].GetPos());
			break;
		case '@':
			BattleEnemy(_Player, EnemyX, EnemyY);
			break;
		default:
			break;
		}
}

void Level::BattleEnemy(Player &_Player, int TargetX, int TargetY)
{
	int EnemyX;
	int EnemyY;
	int PlayerX;
	int PlayerY;
	int AttackPower;
	int AttackResult;
	string EnemyName;

	_Player.GetPosition(PlayerX, PlayerY);

	for (int i = 0; i < _Enemies.size(); i++)
	{
		_Enemies[i].GetPosition(EnemyX, EnemyY);
		EnemyName = _Enemies[i].GetName();

		if (TargetX == EnemyX && TargetY == EnemyY)
		{

			//Battle Starts

			//Player Attacks
			AttackPower= _Player.Attack();
			cout<<"\nPlayer Attacks "<<EnemyName<<" with Power "<<AttackPower<<endl;
			system("PAUSE");
			AttackResult= _Enemies[i].TakeDamage(AttackPower);
			if(AttackResult != 0)
			{
				SetTile(TargetX, TargetY, '.');
				system("color 02");
				cout<<"\nEnemy Died!\n";

				//Remove The Enemy From Data
				_Enemies[i] = _Enemies.back();
				_Enemies.pop_back();
				i--;

				system("PAUSE");
				_Player.AddExperience(AttackResult);
				system("color 07");
				return;
			}

			//Enemy Attacks
			AttackPower = _Enemies[i].Attack();
			cout<<"\n"<<EnemyName<<" Attacks Player with Power "<<AttackPower<<endl;
			system("PAUSE");
			AttackResult= _Player.TakeDamage(AttackPower);
			if(AttackResult != 0)
			{
				cout<<"\nOooopppssss!!! You Died!\n";
				SetTile(PlayerX, PlayerY, '+');
				system("color 04");
				system("PAUSE");
				exit(0);
			}
			return;
		}
	}
}