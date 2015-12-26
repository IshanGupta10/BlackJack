#include <map>
#include <utility>
#include <string>

#include "Blackjack_Cards.h"
#include "Blackjack_Deck.h"

map<pair<char,string>, bool> used_cards;		//HashMap used to check uniqeness of the drawn hand

class Blackjack_Engine
{
	/*
	*	Variables that are used in engine
	*	card = gets the card for the set
	*	player_value = stores the value of player's cards
	*	dealer_value = stores the value of dealer's cards
	*	i = for loop counter and cross checking
	*	dealer and players = are sets of cards generated
	*	player = stores the name of the player
	*	decks = used in stroing the value of decks generated
	*/
	
	char card;
	int player_value , dealer_value ;
	int  i ;

	pair<char,string> dealer[4],players[4];
	string player,decks;

	Blackjack_Deck deck;
	Blackjack_Cards cards;

	public:

	/*
	*	The Constructor initializes the values for the
	*	variables declared in private and starts the game
	*	engine by calling the startGame function. 
	*/

	Blackjack_Engine(string x)
	{
		player = x;
        player_value = 0;
        dealer_value = 0;
        i = 0;
		startGame();
	}

	/*
	*	displayDealer() 
	*	
	*	Parameters = None
	*	Return Type = None
	*	Description = Displays the cards of the Dealer
	*/

	void displayDealer()
	{
		cout<<"Dealer's cards "<<"          ";
		for (int i = 0; i < 4; ++i)
		{	
			if(dealer[i].first == 'X')
				cout<<10<<" "<<dealer[i].second<<" ";
			else
				cout<<dealer[i].first<<" "<<dealer[i].second<<" ";
		}
		cout<<'\n';
	}

	/*
	*	dealerValue() 
	*	
	*	Parameters = None
	*	Return Type = None
	*	Description = Calculates the value of cards of the Dealer
	*/

	void dealerValue()
	{
		for (int i = 0; i < 4; ++i)
		{
			//cout<<dealer[i].first<<" value "<<cards.cardValue(dealer[i].first)<<'\n';
			dealer_value += cards.cardValue(dealer[i].first); 
		}
		if((dealer[0].first == 'A' || dealer[1].first == 'A') && dealer_value > 21)
			dealer_value -= 10;
		//cout<<"Dealer's Value: "<<dealer_value<<'\n';
	}

	/*
	*	playerValue() 
	*	
	*	Parameters = None
	*	Return Type = None
	*	Description = Calculates the value of cards of the Player
	*/

	void playerValue()
	{
		for (int i = 0; i < 4; ++i)
		{
			//cout<<players[i].first<<" value "<<cards.cardValue(players[i].first)<<'\n';
			player_value += cards.cardValue(players[i].first); 
		}
		if((players[0].first == 'A' || players[1].first == 'A') && player_value > 21)
			player_value -= 10;

		//cout<<"Player's Value: "<<player_value<<'\n';
	}

	/*
	*	displayPlayer() 
	*	
	*	Parameters = None
	*	Return Type = None
	*	Description = Displays the cards of the Player
	*/

	void displayPlayer()
	{
		cout<<player<<"'s cards "<<"          ";
		for (int i = 0; i < 4; ++i)
		{
			if(players[i].first == 'X')
				cout<<10<<" "<<players[i].second<<" ";
			else
				cout<<players[i].first<<" "<<players[i].second<<" ";
		}
		cout<<'\n';
	}

	/*
	*	handChecker() 
	*	
	*	Parameters = Pair of card and its corresponding deck
	*	Return Type = True/ False
	*	Description = True if hand already present; False if not present
	*/

	bool handChecker(pair<char,string> check)
	{
		if(used_cards.find(check) != used_cards.end())
			return true;
		else
			return false;
	}

	/*
	*	clearScreen() 
	*	
	*	Parameters = None
	*	Return Type = None
	*	Description = Clears the screen by calling new line multiple times
	*/
	
	void clearScreen()
	{
		for (int i = 0; i < 50; ++i)
			cout<<'\n';
	}

	/*
	*	findWinner() 
	*	
	*	Parameters = None
	*	Return Type = True/ False
	*	Description = Decides the winner by comparing Player and Dealer's card 
					  values; True if Dealer wins, False if Player wins.
	*/

	bool findWinner()
	{
		return dealer_value >= player_value ? true : false;
	}

	/*
	*	startGame() 
	*	
	*	Parameters = None
	*	Return Type = None
	*	Description = Start engine of BlackJack game. Deals the first two cards. 
	*/	

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

		//displayDealer();
		dealerValue();
		
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
		
		//displayPlayer();
		playerValue();
	}

	~Blackjack_Engine()
	{
		used_cards.clear();
	}
};