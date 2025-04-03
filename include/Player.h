// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Card.h"

class Player {

private:
    bool isAllIn;
    bool hasFolded;
    int chips;
    int currentBet;

public:
    virtual ~Player() = default; // Virtual destructor for proper cleanup
    
    std::string name;
    std::vector<Card> hand;

    // Constructor to initialize player's name and starting money
    Player(const std::string &name, int startingChips);

    // return the player's hand
    std::vector<Card> getHand() const;

    // Add a card to the player's hand
    void receiveCard(const Card &card);

    // Clear the player's hand for new rounds
    void clearHand();

    // Check if the player wants to hit (draw a card)
    void fold();

    // Display the player's current hand
    void showHand() const;

    // Get the current money the player has
    int getChips() const;

    // Deduct chips for a bet
    bool placeBet(int amount);  // Added this function

    // Get player's name
    std::string getName() const;


    // Set player as folded
    void setHasFolded(bool folded);
    bool getHasFolded() const;

    // Set current bet amount
    void setCurrentBet(int bet);
    int getCurrentBet() const;

    // Mark player as all-in
    void setIsAllIn(bool allIn);
    bool getIsAllIn() const;

};
#endif
