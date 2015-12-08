using namespace std; 

#include "DeckMaker.h"

int main() {

	FileProgram();

	return 0;
}

/* **************************************************************************************************
CHECK COMMANDS & ESABLISH VARIABLES -----------------------------------------------------------------
The function to run the program.
************************************************************************************************** */
void FileProgram() {

	ifstream deckCommands;	// Declare the input filestream variable.
	ofstream dealtCards;	// Declare the output filestream variable.
	string command;			// String variable to hold the command given in the DEAL_FILE.

	/* ***********************************************************
	Integer variable to hold the iterations: ---------------------
	For Shuffle() - The number of times to shuffle.
	For Cut()     - The number of cards to cut off the top.
	*********************************************************** */
	unsigned int iterations;

	bool newDeck = false;	// Boolean value to maintain a check if a NewDeck has been created or not. (Passed by reference into NewDeck().)
	shared_ptr<Card> deck;	// Declare the shared_ptr of the variable that will be holding the address of deck.

	deckCommands.open(COMMANDS_FILE);	// Open the COMMANDS__FILE with ifstream.
	dealtCards.open(DEAL_FILE);			// Open the DEAL_FILE with ofstream.

	/* **************************************
	While loop to read the commands in
	DEAL_FILE and place them into thecommand
	string variable. If the command should
	have an iteration number value then
	continue to read that from the file into
	the iteration integer variable.
	************************************** */
	while (deckCommands >> command) {
		if (command == NEW_DECK_COMMAND) {		// If NEW_DECK_COMMAND is called.
			deck = NewDeck(newDeck);			// Stores the deck (shared_ptr) into Deck if the NEW_DECK_COMMAND is called in the COMMANDS_FILE.
		}
		else if (newDeck) {
			if (command == SHUFFLE_COMMAND) {	// If SHUFFLE_COMMAND is called.
				deckCommands >> iterations;		// Store the number of shuffles into the iterations integer variable.
				Shuffle(deck, iterations);		// Run the Shuffle() functon with the appropriate variables to Shuffle the deck.
			}
			else if (command == CUT_COMMAND) {	// If CUT_COMMAND is called.
				deckCommands >> iterations;		// Store the number of cards to cut off the top into the iterations integer variable.
				Cut(deck, iterations);			// Run the Cut() function with the appropriate variables to Cut the deck.
			}
			else if (command == DEAL_COMMAND) {	// If the DEAL_COMMAND is called.
				Deal(deck, dealtCards);			// Run the Deal() function with the appropriate variables to deal the cards into the DEAL_FILE.
			}
		}
		else {
			continue;							// If none of those commands are given approprately just continue the while loop.
		}
	}

	deckCommands.close();	// Close the COMMANDS_FILE.
	dealtCards.close();		// Close the DEAL_FILE.
}

/* **************************************************************************************************
CREATE A NEW DECK: ----------------------------------------------------------------------------------
Created the new Deck from the struct and enums.
************************************************************************************************** */
shared_ptr<Card> NewDeck(bool &newDeck) {

	// Allocate the memory for the array of Card structures.
	shared_ptr<Card> deck(new Card[NUM_CARDS]);
	// For loop for each card.
	for (unsigned int currentCard = START_ZERO; currentCard < NUM_CARDS;) {
		// For loop for each suit.
		for (unsigned int suit = SPADES; suit <= DIAMONDS; suit++) {
			// For loop for each rank.
			for (unsigned int rank = ACE; rank <= TWO; rank++, currentCard++) {
				// Store the current iteration's static_casted CardSuit suit to the new Deck.
				(deck.get() + currentCard)->suit = static_cast<CardSuit>(suit);
				// Store the current iteration's statuc_casted CardRank rank to the new Deck.
				(deck.get() + currentCard)->rank = static_cast<CardRank>(rank);
			}
		}
	}
	// Set newDeck to true so that the program knows that a NewDeck exists.
	newDeck = true;
	// Return the deck shared_ptr to the caller.
	return deck;
}

/* **************************************************************************************************
CUT THE DECK: ---------------------------------------------------------------------------------------
Modify the array so that the top # cards (where # is the number to cut) are placed at the end
of the array.  If the # (number of cards to cut) isnít a valid value your program should ignore
the Cut command.
************************************************************************************************** */
void Cut(shared_ptr<Card> &cutDeck, const unsigned int NUM_CUT) {
	// Check if the passed NUM_CUT is less than the number of cards in the deck and greater than 0
	if ((NUM_CUT < NUM_CARDS) && (NUM_CUT > POSSIBLE_ZERO)) {
		// Create a unique_ptr for a new temporary deck.
		unique_ptr<Card> tempDeck(new Card[NUM_CARDS]);
		/* ***************************************************
		For loop to copy the deck that is passed by reference.
		*************************************************** */
		for (unsigned int r = START_ZERO; r < NUM_CARDS; r++) {
			// Set the passed by reference deck suit in the current iteration to the temporary deck's suit.
			(tempDeck.get() + r)->suit = (cutDeck.get() + r)->suit;
			// Set the passed by reference deck rank in the current iteration to the temporary deck's rank.
			(tempDeck.get() + r)->rank = (cutDeck.get() + r)->rank;
		}
		/* ***************************************************
		For loop to take the top NUM_CUT from the tempDeck
		and put it on the bottom of the passed by reference
		cutDeck. Then fill the rest of the cutDeck with the
		remaining cards in tempDeck.
		*************************************************** */
		for (unsigned int i = START_ZERO; i < NUM_CARDS; i++) {
			// Place the cut cards on the bottom.
			if (i < NUM_CUT) {
				(cutDeck.get() + ((NUM_CARDS - NUM_CUT) + i))->rank = (tempDeck.get() + i)->rank;
				(cutDeck.get() + ((NUM_CARDS - NUM_CUT) + i))->suit = (tempDeck.get() + i)->suit;
			}
			// Place the rest of the cards on the top of the deck.
			else {
				(cutDeck.get() + (i - NUM_CUT))->rank = (tempDeck.get() + i)->rank;
				(cutDeck.get() + (i - NUM_CUT))->suit = (tempDeck.get() + i)->suit;
			}
		}
	}
}


/* **************************************************************************************************
SHUFFLE THE DECK: -----------------------------------------------------------------------------------
Perform a perfect shuffle. Shuffle cuts the deck in half, creating a left deck and right deck.
The left deck contains the top 26 cards and the right deck contains the bottom 26 cards.
Your program will alternate between the two decks (left deck first) taking the last card in the
array and placing it at the end of the new shuffled deck, repeating the process until all the cards
are shuffled.  If the # (number of times to shuffle the deck) isnít a valid value your program should
ignore the Shuffle command.
************************************************************************************************** */
void Shuffle(shared_ptr<Card> &shuffledDeck, const unsigned int TIMES) {
	/* *********************************************************************
	For loop for number of times to shuffle.
	********************************************************************* */
	for (unsigned int shuffles = START_ZERO; shuffles < TIMES; shuffles++) {
		// Create a unique_ptr for the left half of the deck.
		unique_ptr<Card> leftDeck(new Card[NUM_CARDS / HALF]);
		// Create a unique_ptr for the right half of the deck.
		unique_ptr<Card> rightDeck(new Card[NUM_CARDS / HALF]);
		/* ****************************************************
		For loop to split the deck into the two halves.
		Top half = left, Bottom half = right.
		**************************************************** */
		for (unsigned int i = START_ZERO; i < NUM_CARDS; i++) {
			// If it is pulling cards from the top half of the deck, put it in the left deck.
			if (i < NUM_CARDS / HALF) {
				(leftDeck.get() + i)->rank = (shuffledDeck.get() + i)->rank;
				(leftDeck.get() + i)->suit = (shuffledDeck.get() + i)->suit;
			}
			// If it is pulling cards from the bottom half of the deck, put it in the right deck.
			else if (i >= NUM_CARDS / HALF) {
				(rightDeck.get() + (i - (NUM_CARDS / HALF)))->rank = (shuffledDeck.get() + i)->rank;
				(rightDeck.get() + (i - (NUM_CARDS / HALF)))->suit = (shuffledDeck.get() + i)->suit;
			}
		}
		/* ************************************************************************
		Starting from the bottom of the left deck and alternating between the left
		and right decks, rebuild into the shuffled deck.
		************************************************************************ */
		for (int s = START_ONE, d = START_ONE; d <= (NUM_CARDS / HALF); s++, d++) {
			(shuffledDeck.get() + (NUM_CARDS - s))->rank = (leftDeck.get() + ((NUM_CARDS / HALF) - d))->rank;
			(shuffledDeck.get() + (NUM_CARDS - s))->suit = (leftDeck.get() + ((NUM_CARDS / HALF) - d))->suit;
			s++;
			(shuffledDeck.get() + (NUM_CARDS - s))->rank = (rightDeck.get() + ((NUM_CARDS / HALF) - d))->rank;
			(shuffledDeck.get() + (NUM_CARDS - s))->suit = (rightDeck.get() + ((NUM_CARDS / HALF) - d))->suit;
		}
	}
}

/* **************************************************************************************************
TRANSLATE TO CARD NAME STRINGS: ---------------------------------------------------------------------
Translates all the cards into user-readable strings.
************************************************************************************************** */
string TranslateCard(Card card) {
	// Declare the string that will be returned.
	string cardString;
	// Append strings together "rank of suit".
	cardString.append(RANKS[card.rank]).append(OUTPUT_DELIMITER).append(SUITS[card.suit]);
	// Return the new string.
	return cardString;
}

/* **************************************************************************************************
DEAL CARDS: -----------------------------------------------------------------------------------------
Write the contents of the deck to a file named DealCards.txt.  Start with the 1st element in the
array.
************************************************************************************************** */
void Deal(shared_ptr<Card> finalDeck, ofstream &outputFile) {
	/* ****************************************************
	For loop to iterate through the deck and output the
	translated string values into the DEAL_FILE.
	**************************************************** */
	for (unsigned int i = START_ZERO; i < NUM_CARDS; i++) {
		// Output after using TranslateCard() to change the integers into their string counter parts.
		outputFile << TranslateCard(*(finalDeck.get() + i)) << endl;
	}
}
