#include "Enemy.h"
#include<random>
#include<ctime>


Enemy::Enemy(string Name, char Tile, int Level, int Attack, int Defence, int Health, int Experience)
{
	_Name = Name;
	_Tile = Tile;
	_Level= Level;
	_Attack= Attack;
	_Defence= Defence;
	_Health= Health;
	_Experience= Experience;

}

int Enemy::Attack()
{
	static default_random_engine RandomEngine(time(0));
	uniform_int_distribution<int> AttackChance(0, _Attack);

	return AttackChance(RandomEngine);
}

int Enemy::TakeDamage(int Attack)
{
	Attack-= _Defence;
	if (Attack > 0)
	{
		_Health-= Attack;

		if(_Health <= 0)
			return _Experience;
	}

	return 0;
}

char Enemy::EnemyRandMove(int PlayerX, int PlayerY)
{
	static default_random_engine Engine(time(0));
	uniform_int_distribution<int> RandMove(0, 5);

	int Dist;
	int DiffX= _X - PlayerX;
	int DiffY= _Y - PlayerY;
	int AbDiffX=  abs(DiffX);
	int AbDiffY= abs(DiffY) ;

	Dist= AbDiffX + AbDiffY;

	if ( Dist <= 5)
	{
		if (AbDiffX > AbDiffY)
		{
			if (DiffX > 0)
			{
				return 'a';
			}
			else
			{
				return 'd';
			}
		}
		else
		{
			if (DiffY > 0)
			{
				return 'w';
			}
			else
			{
				return 's';
			}
		}
	}

	int RandomMove = RandMove(Engine);

	switch (RandomMove)
	{
	case 0:
		return 'a';
	case 1:
		return 's';
	case 2:
		return 'd';
	case 3:
		return 'w';
	default:
		return '.';
	}
}

//Set Pos of Enemy
void Enemy::SetPosition(int X, int Y)
{
	_X= X;
	_Y= Y;
}

//To Get The Pos of The Enemy Using Vars
void Enemy::GetPosition(int &X, int &Y)
{
	X= _X;
	Y= _Y;
}