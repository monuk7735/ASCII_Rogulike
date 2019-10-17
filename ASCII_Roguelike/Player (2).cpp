#include "Player.h"
#include<random>
#include<ctime>
#include<iostream>

using namespace std;

//Constructor to init vars
Player::Player()
{
	_X=0;
	_Y=0;
}

//To init Player Props
void Player::init(int Level, int Health, int Attack, int Defence, int Experience)
{
	_Level= Level;
	_Health= Health;
	_Attack= Attack;
	_Defence= Defence;
	_Experience= Experience;
}

int Player::Attack()
{
	static default_random_engine RandomEngine(time(0));
	uniform_int_distribution<int> AttackChance(0, _Attack);

	return AttackChance(RandomEngine);
}

void Player::AddExperience(int Exp)
{
	_Experience+= Exp;

	while (_Experience > 50)
	{
		_Experience= 50;
		_Level++;
		_Health+= 10;
		_Attack+= 5;
		_Defence+= 5;
		cout<<"Promoted to Next Level\n";
		system("PAUSE");
	}
}

int Player::TakeDamage(int Attack)
{
	Attack-= _Defence;
	if (Attack > 0)
	{
		_Health-= Attack;

		if(_Health <= 0)
			return 1;
	}

	return 0;
}


//Set Pos of Player
void Player::SetPosition(int X, int Y)
{
	_X= X;
	_Y= Y;
}

//To Get The Pos of The Player Using Vars
void Player::GetPosition(int &X, int &Y)
{
	X= _X;
	Y= _Y;
}

void Player::DispStats()
{
	cout<<"Level: "<<_Level<<endl;
	cout<<"Health: "<<_Health<<endl;
	cout<<"Attack Power: "<<_Attack<<endl;
	cout<<"Defence Power: "<<_Defence<<endl;
	cout<<"Experience: "<<_Experience<<endl<<endl;
}
