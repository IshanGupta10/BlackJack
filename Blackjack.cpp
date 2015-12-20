#include <iostream>
#include <conio>
#include <cstdlib>
#include <map>
#include <utility>
// #include <Blackjack_Cards.h>
// #include <Blackjack_Deck.h>
#include <Blackjack_Engine.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string player;
	char choice,new_game;
	
	do
	{
		cout<<"Please enter your name: ";
		cin>>player;
		clrscr();
		
		cout<<"\t \t Welcome to the BlackJack!!! \n \n";
		cout<<"The rules are standard. Let us begin.\n";
		
		cout<<"Dealing first two cards - - - \n";
		Blackjack_Engine game();


		//To start a new game, enter a choice ~~~
		cout<<"A new game?(Y/N) : "
		cin>>new_game;
	}while(new_game == 'y' || new_game == 'Y');
	
	return 0;
}