#include "card.h"

void Card::print() const {
    std::cout << toString();
}

std::string Card::toString() const {
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    std::string ranks[] = {"", "", "2", "3", "4", "5", "6", "7", "8", "9", "10", 
                           "Jack", "Queen", "King", "Ace"};

    return ranks[static_cast<int>(rank)] + " of " + suits[static_cast<int>(suit)] + "\n";
}// Added another stuff here