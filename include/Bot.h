// Bot.h
#ifndef BOT_H
#define BOT_H

#include "Player.h"
#include <random>

class Bot : public Player {
public:
    Bot(const std::string& name, int chips);
    void decideAction(int currentBet);  // Simple random logic
};
#endif