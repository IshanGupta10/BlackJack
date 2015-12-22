#include <map>
#include <utility>
#include <string>

#include "Blackjack_Cards.h"
#include "Blackjack_Deck.h"

map<pair<char,string>, bool> used_cards;

class Blackjack_Engine
{
	public:
	
	char card;
	int player_value = 0, dealer_value = 0;
	int  i = 0;
	
	pair<char,string> dealer[4],players[4];
	string player,decks;
	
	Blackjack_Deck deck;
	Blackjack_Cards cards;
	
	Blackjack_Engine(char x)
	{
		//cout<<"Reached Here "<<'\n';
		startGame();
	}

	void displayDealer()
	{

	}

	void displayPlayer()
	{

	}

	bool handChecker(pair<char,string> check)
	{
		if(used_cards.find(check) != used_cards.end())
			return true;
		else
			return false;
	}

	void startGame()
	{
		
		while(i<2)
		{
			card = cards.generateCard();
			decks = deck.getDeck();
			dealer[i] = make_pair(card,decks);
			if(handChecker(dealer[i]))
			{
				if(i == 0)
					continue;
				else
					i--;
			}
			else
			{	
				used_cards[dealer[i]] = true;
				i++;
			}
		}

		i = 0;

		while(i<2)
		{
			card = cards.generateCard();
			decks = deck.getDeck();
			players[i] = make_pair(card,decks);
			if(handChecker(players[i]))
			{
				if(i == 0)
					continue;
				else
					i--;
			}
			else
			{	
				used_cards[players[i]] = true;
				i++;
			}
		}
	}

//	~Blackjack_Engine();

	/* data */
};
