#pragma once
using namespace std;

const unsigned int
NUM_CARDS = 52,	// Number of Cards in a Deck.
HALF = 2,	// Used to divide by two.
CORRECTION = 1,	// Used to correct the array iteration.
START_ZERO = 0,	// Start at zero.
START_ONE = 1,	// Start at one.
POSSIBLE_ZERO = 0;	// Possible bad values

const string
COMMANDS_FILE = "DeckCommands.txt",		// The file that has the commands to follow.
DEAL_FILE = "DealCards.txt",			// The file to deal the cards to.
NEW_DECK_COMMAND = "NewDeck",			// Command for NewDeck().
SHUFFLE_COMMAND = "Shuffle",			// Command for Shuffle().
CUT_COMMAND = "Cut",					// Command for Cut().
DEAL_COMMAND = "Deal",					// Command or Deal().
// COMMANDS[]			= { "NewDeck","Shuffle","Cut","Deal" },
SUITS[] = { "Spades","Hearts","Clubs","Diamonds" },	// Possile Card Suits
RANKS[] = { "Ace","King","Queen","Jack","Ten","Nine","Eight","Seven","Six","Five","Four","Three","Two" }, // Possible Card Ranks.
OUTPUT_DELIMITER = " of ";				// The delimiter separating the outputted card name strings into the DEAL_FILE.

enum CardSuit {
	// Enumerator for Card Suits.
	SPADES = 0,
	HEARTS = 1,
	CLUBS = 2,
	DIAMONDS = 3
};

enum CardRank {
	// Enumerator for Card Ranks/Pips.
	ACE = 0,
	KING = 1,
	QUEEN = 2,
	JACK = 3,
	TEN = 4,
	NINE = 5,
	EIGHT = 6,
	SEVEN = 7,
	SIX = 8,
	FIVE = 9,
	FOUR = 10,
	THREE = 11,
	TWO = 12
};

struct Card {
	// Structure for the cards in the deck.
	CardSuit suit;
	CardRank rank;
};

// Function Prototypes
void FileProgram();
shared_ptr<Card> NewDeck(bool &newDeck);
void Cut(shared_ptr<Card> &cutDeck, const unsigned int NUM_CUT);
void Shuffle(shared_ptr<Card> &shuffledDeck, const unsigned int TIMES);
string TranslateCard(Card card);
void Deal(shared_ptr<Card> finalDeck, ofstream &file);
