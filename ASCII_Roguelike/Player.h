#pragma once

class Player
{
public:
	Player();

	void init(int Level, int Health, int Attack, int Defence, int Experience);

	//Setters
	void SetPosition(int X, int Y);

	//Getters
	void GetPosition(int &X, int &Y);

	void DispStats();

	int Attack();
	int TakeDamage(int Attack);
	void AddExperience(int Exp);

private:
	//Propeties
	int _Level;
	int _Health;
	int _Attack;
	int _Defence;
	int _Experience;

	//Pos
	int _X;
	int _Y;
};

