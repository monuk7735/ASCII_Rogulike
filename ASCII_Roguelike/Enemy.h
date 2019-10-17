#pragma once

#include<string>

using namespace std;

class Enemy
{
public:
	Enemy(string Name, char Tile, int Level, int Attack, int Defence, int Health, int Experience);

	int Attack();
	int TakeDamage(int Attack);

	//To Get Automatic Move Command
	char EnemyRandMove(int PlayerX, int PlayerY);

	char GetPos()
	{
		return _Tile;
	}

	//Setters
	void SetPosition(int X, int Y);

	//Getters
	void GetPosition(int &X, int &Y);

	

	string GetName()
	{
		return _Name;
	}

private:
	string _Name;
	char _Tile;

	int _Level;
	int _Health;
	int _Attack;
	int _Defence;
	int _Experience;

	//Pos
	int _X;
	int _Y;
};

