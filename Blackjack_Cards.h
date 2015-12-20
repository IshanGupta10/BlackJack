#define CARD_SIZE 13

class Blackjack_Cards
{
	char cards[CARD_SIZE];

public:

	//Constructor initializes the cards.
	Blackjack_Cards()
	{
		card[] = {'A', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K'};
	}

	//Generates a random card and returns for Card generation
	char generateCard()
	{
		int random_card = rand() % 13;
		return card[random_card];
	}

	int cardValue(char card)
	{
		if(card >= '2' && card <= '10')
			return card - '0';
		else if(card == 'J' || card == 'Q' || card == 'K')
			return 10; 
		else
			return -1;
	}

	~Blackjack_Cards();

	/* data */
};