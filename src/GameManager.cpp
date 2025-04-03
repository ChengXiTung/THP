// GameManager.cpp
#include "GameManager.h"
#include <iostream>

GameManager::GameManager() 
    : pot(0), dealerPosition(0), highestBet(0), activePlayers(0) {}

GameManager::~GameManager() {
    for (Player* p : players) delete p;
}


void GameManager::addPlayer(Player* player) {
    players.push_back(player);
    activePlayers++;
}

void GameManager::postBlinds() {
    int smallBlindPos = (dealerPosition + 1) % players.size();
    int bigBlindPos = (dealerPosition + 2) % players.size();

    players[smallBlindPos]->placeBet(smallBlind);
    pot += smallBlind;
    
    players[bigBlindPos]->placeBet(bigBlind);
    pot += bigBlind;
    
    highestBet = bigBlind;
}

void GameManager::dealHoleCards() {
    for (int i = 0; i < 2; ++i) {
        for (Player* p : players) {
            p->receiveCard(deck.draw());
        }
    }
}

void GameManager::dealCommunityCards(int count) {
    for (int i = 0; i < count; ++i) {
        communityCards.push_back(deck.draw());
    }
}

void GameManager::showCommunityCards() const {
    std::cout << "\nCommunity Cards: ";
    for (const Card& card : communityCards) {
        card.print();
        std::cout << " ";
    }
    std::cout << "\n";
}

void GameManager::determineWinner() {
    // !!Temporary!! implementation - just award pot to first non-folded player
    for (Player* p : players) {
        if (!p->getHasFolded()) {
            std::cout << p->getName() << " wins " << pot << " chips!\n";
            return;
        }
    }
}

void GameManager::startBettingRound() {
    // Start with player after big blind
    int startPos = (dealerPosition + 3) % players.size();
    
    for (int i = 0; i < players.size(); ++i) {
        int currentPos = (startPos + i) % players.size();
        Player* p = players[currentPos];

        if (p->getHasFolded()) continue;

        // Human player interaction
        if (dynamic_cast<Bot*>(p) == nullptr) {
            std::cout << "Your turn. Current bet: " << highestBet << std::endl;
            std::cout << "1: Fold | 2: Call | 3: Raise\nChoice: ";
            int choice;
            std::cin >> choice;
            
            switch (choice) {
                case 1: p->fold(); break;
                case 2: p->placeBet(highestBet - p->getCurrentBet()); break;
                case 3: {
                    std::cout << "Raise amount: ";
                    int raise;
                    std::cin >> raise;
                    highestBet += raise;
                    p->placeBet(highestBet - p->getCurrentBet());
                    break;
                }
            }
        }
        // Bot logic
        else {
            if (rand() % 3 == 0) p->fold();
            else p->placeBet(highestBet - p->getCurrentBet());
        }
    }
}

void GameManager::playGame() {
    deck.shuffle();
    dealHoleCards();
    
    // Pre-flop
    postBlinds();
    startBettingRound();
    
    // Flop
    dealCommunityCards(3);
    showCommunityCards();
    startBettingRound();
    
    // Turn
    dealCommunityCards(1);
    showCommunityCards();
    startBettingRound();
    
    // River
    dealCommunityCards(1);
    showCommunityCards();
    startBettingRound();
    
    determineWinner();
}