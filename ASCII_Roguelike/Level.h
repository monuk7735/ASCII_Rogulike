#pragma once

#include<vector>
#include<string>
#include"Player.h"
#include"Enemy.h"

using namespace std;

class Level
{
public:
	Level();

	void LoadLevel(string FileName, Player &_Player);
	void PrintLevel();
	void MovePlayer(char Input, Player &_Player);
	
	void UpdateEnemyPos(Player &_Player);

	//Getter
	char GetTile(int X, int Y);
	
	//Setter
	void SetTile(int X, int Y, char Tile);

private:
	vector <string> _LevelData;
	vector <Enemy> _Enemies;

	void ProcessPlayerMove(Player &_Player, int TargetX, int TargetY);
	void ProcessEnemyMove(Player &_Player, int EnemyIndex, int TargetX, int TargetY);
	void BattleEnemy(Player &Player, int TargetX, int TargetY);
};

