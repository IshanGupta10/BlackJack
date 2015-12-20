#include <Blackjack_Cards.h>
#include <Blackjack_Deck.h>

map<pair<char,string>, bool> used_cards;

class Blackjack_Engine
{
	char card;
	int player_value = 0, dealer_value = 0;
	int  i = 0;
	pair<string,char> dealer[4],players[4];
	string player,decks;

public:

	Blackjack_Deck deck;
	Blackjack_Cards cards;
	
	Blackjack_Engine()
	{
		startGame();
	}

	void displayDealer()
	{

	}

	void displayPlayer()
	{

	}

	bool handChecker(pair<string,char> check)
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
			dealer[i] = make_pair(decks,card);
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
			players[i] = make_pair(decks,card);
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


	~Blackjack_Engine();

	/* data */
};