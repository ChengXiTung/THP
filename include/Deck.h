// Deck.h
#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck();          // Constructor
    void shuffle();  // Shuffle the deck
    Card draw();     // Draw a card from the deck
    void reset();    // Reset deck for a new round
    void printDeck();// Print the deck (for debugging)
};

#endif
