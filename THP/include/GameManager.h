#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "deck.h"
#include "player.h"
#include <vector>

class GameManager {
private:
    Deck deck;
    std::vector<Player> players;
    std::vector<Card> communityCards;
    int pot;  // Total chips in the pot

public:
    GameManager();
    
    void addPlayer(const std::string& name, int chips);  
    void dealHoleCards();  
    void dealCommunityCards(int count);  
    void showCommunityCards() const;  
    void startBettingRound();  
    void determineWinner();  

    void playGame();  // Main game loop
};

#endif
