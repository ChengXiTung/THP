#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "card.h"

class Player {
private:
    std::string name;
    std::vector<Card> hand;


    int chips;  // Corrected from "money" to "chips"
    bool hasFolded_;
    int currentBet_;
    bool isAllIn_;

public:
    // Constructor to initialize player's name and starting money
    Player(const std::string &name, int startingChips);

    std::vector<Card> getHand() const;
    // Add a card to the player's hand
    void receiveCard(const Card &card);

    // Clear the player's hand (useful for new rounds)
    void clearHand();

    void fold();  // Added this function

    // Display the player's current hand
    void showHand() const;

    // Get the current money the player has
    int getChips() const;  // Changed from "getMoney()" to "getChips()"

    // Deduct chips for a bet
    bool placeBet(int amount);  // Added this function

    // Add winnings to the player's balance
    void addWinnings(int amount);

    // Get player's name
    std::string getName() const;


    bool hasFolded() const { 
        return hasFolded_; 
    }  // Check if player folded

    void setFolded(bool folded) { 
        hasFolded_ = folded; 
    } // Set player as folded

    int getCurrentBet() const { 
        return currentBet_; 
    } // Get current bet amount

    void setCurrentBet(int bet) { 
        currentBet_ = bet; 
    } // Set current bet amount

    bool isAllIn() const { 
        return isAllIn_; 
    }  // Check if player is all-in

    void setAllIn(bool allIn) { 
        isAllIn_ = allIn; 
    } // Mark player as all-in

};

#endif
