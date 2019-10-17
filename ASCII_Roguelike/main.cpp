#include<iostream>
#include<conio.h>

#include"GameSystem.h"
#include"Player.h"
#include"Level.h"

using namespace std;

void PlayGame(string _LevelFile)
{
	GameSystem _GameSystem(_LevelFile);
	_GameSystem.PlayGame();
}

void CustomLevel()
{
	cout<<"\n1. Level1.txt\n";
	cout<<"2. Level2.txt\n";
	cout<<"3. Level3.txt\n";
	cout<<"4. Level4.txt\n";
	cout<<"Enter an Option: ";
	int Option;
	cin>>Option;
	switch (Option)
	{
	case 1:
		PlayGame("Level1.txt");
		break;
	case 2:
		PlayGame("Level2.txt");
		break;
	case 3:
		PlayGame("Level3.txt");
		break;
	case 4:
		PlayGame("Level4.txt");
		break;
	default:
		cout<<"Error! Wrong Option\n";
		break;
	}
}

void ToCreateLevel()
{
	system("cls");
	cout<<"\n\nYou can Easily Create Level and Place it in Documents/Visual Studio 20XX/Projects/ASCII_Roguelike/ASCII_Roguelike/";
	cout<<"\nChoose Available Option in Main Menu to See Available Level Names\n";
	cout<<"You Need to Use These ASCII Characters\n";
	cout<<"# for Wall\n";
	cout<< ". for Air\n";
	cout<<"@ for Player\n";
	cout<<"D for Dragon\n";
	cout<<"S for Snake\n";
	cout<<"g for Goblin\n";
	_getch();
}

void Instructions()
{

}

void Options()
{
	cout<<"1. Play Default Level\n";
	cout<<"2. Available Custom Level Names\n";
	cout<<"3. Instruction to Create a Level\n";
	cout<<"4. Instructions to Play The Game\n";
	cout<<"5. Exit\n";
	int Option;
	cout<<"Enter an Option: ";
	cin>>Option;
	switch (Option)
	{
	case 1:
		PlayGame("Default.txt");
		break;
	case 2:
		CustomLevel();
		break;
	case 3:
		ToCreateLevel();
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}
}

void main()
{
	while(1)
	{
		system("cls");
		cout<<"\n\tWelcome to ASCII Rogulike\n";
		cout<<"\n\t   Made By monuk7735\n\n\n";
		Options();
	}
}