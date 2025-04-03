// main.cpp
#include "GameManager.h"
#include "Bot.h"
#include <iostream>

int main() {
    GameManager game;

    // Add human player
    Player* human = new Player("You", 1000);
    game.addPlayer(human);

    // Add 3 bots
    for (int i = 1; i <= 3; i++) {
        Bot* bot = new Bot("Bot " + std::to_string(i), 1000);
        game.addPlayer(bot);
    }

    // Start the game
    game.playGame();
    return 0;
}