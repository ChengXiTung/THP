// Bot.cpp
#include "Bot.h"
#include <iostream>

Bot::Bot(const std::string& name, int chips) : Player(name, chips) {}

void Bot::decideAction(int currentBet) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 2);

    int action = dist(gen);
    switch (action) {
        case 0: 
            fold();
            break;
        case 1:
            // Call: Match current bet
            placeBet(currentBet - getCurrentBet());
            break;
        case 2:
            // Raise: Add 50 to current bet
            placeBet((currentBet + 50) - getCurrentBet());
            break;
    }
}