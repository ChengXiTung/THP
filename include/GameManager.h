// GameManager.h
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Deck.h"
#include "Player.h"
#include "Card.h"
#include "Bot.h"
#include <vector>

class GameManager {
private:

    Deck deck;
    std::vector<Player*> players;
    std::vector<Card> communityCards;

    int pot;
    int dealerPosition;
    int highestBet;       // Track highest bet in current round
    int activePlayers;    // Track non-folded players

    // Blind management
    int smallBlind = 50;
    int bigBlind = 100;

public:
    GameManager();
    ~GameManager(); // Destructor to clean up dynamically allocated players

    void addPlayer(Player* player);
    void rotateDealer();  // Rotate dealer position

    void dealHoleCards();  
    void dealCommunityCards(int count);  
    void showCommunityCards() const;

    void startBettingRound();  
    void determineWinner();
    void postBlinds(); // Automatically posts small/big blinds based on dealer position
    void playGame();  // Main game loop
};
#endif
