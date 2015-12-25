#include <iostream>
#include <cstdlib>
#include <string>

#include "Blackjack_Engine.h"
using namespace std;

/*	
*	BlackJack Game ~~~~~~~~~~	
*	Standard rules of 2 cards dealing
*	A can be 1 or 11
*	J, Q, and K are 10
*	Value cards have their respective values.
*	Anyone (player/dealer) that reaches 21 or closer first
*	wins the game.
*/

int main(int argc, char const *argv[])
{
	string player;
	char new_game = 'y';
	
	cout<<"Hello! "<<'\n';
	
	while(new_game == 'y' || new_game == 'Y')
	{
		cout<<"Please enter your name: ";									//Gets the players name
		cin>>player;
		
		cout<<'\n'<<"\t \t \tWelcome to the BlackJack!!! \n \n";
		cout<<"The rules are standard. Let us begin.\n";																									
																				
		cout<<"Dealing first two cards - - - \n \n";
		Blackjack_Engine game(player);

		game.displayDealer();
		game.displayPlayer();

		if(game.findWinner())
			cout<<'\n'<<"\t \t \tWinner is Dealer!!! "<<"\n \n";
		else
			cout<<'\n'<<"\t \t \tWinner is "<<player<<"!!! "<<"\n \n";

		//To start a new game, enter a choice ~~~
		cout<<"A new game?(Y/N) : ";
		cin>>new_game;
		cout<<'\n';
		
		// if(new_game == 'y' || new_game == 'Y')
		// 	game.clearScreen();
	}
	return 0;
}