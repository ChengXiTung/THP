#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <string>

enum class Suit { Hearts, Diamonds, Clubs, Spades };
enum class Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, 
                  Jack, Queen, King, Ace };

struct Card {
    Rank rank;
    Suit suit;

    // Print formatted card name (e.g., "Ace of Spades")
    void print() const;
    
    // Return string representation (useful for debugging)
    std::string toString() const;
};

#endif
