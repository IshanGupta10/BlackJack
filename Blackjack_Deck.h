#include <string>
using namespace std;

#define DECK_SIZE 4

class Blackjack_Deck
{
	string deck[DECK_SIZE];			//For the different decks

public:
	
	//Constructor initializes the deck.
	Blackjack_Deck()
	{
		deck[DECK_SIZE] = {"Spades", "Hearts", "Clubs", "Diamonds"}; 
	}

	//Generates a random deck and returns for Card generation
	string getDeck()
	{
		int random_deck = rand() % DECK_SIZE;		//uses cstdlib header for rand function
		return deck[random_deck];
	}

	~Blackjack_Deck();

	/* data */
};