#include <iostream>
#include <cstdlib>
#include <map>
#include <utility>
#include <string>

#include "Blackjack_Engine.h"
using namespace std;

int main(int argc, char const *argv[])
{
	string player;
	char choice,new_game = 'y';
	cout<<"Hello! "<<'\n';
	while(new_game == 'y' || new_game == 'Y')
	{
		cout<<"Please enter your name: ";
		cin>>player;
		//clrscr();
		
		cout<<'\n'<<"\t \t Welcome to the BlackJack!!! \n \n";
		cout<<"The rules are standard. Let us begin.\n";
		
		cout<<"Dealing first two cards - - - \n";
		Blackjack_Engine game();

		//To start a new game, enter a choice ~~~
		cout<<"A new game?(Y/N) : ";
		cin>>new_game;
		cout<<'\n';
	}
	return 0;
}