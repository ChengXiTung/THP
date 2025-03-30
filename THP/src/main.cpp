// main.cpp
#include "deck.h"
#include "card.h"
#include "player.h"
#include "GameManager.h"
#include <iostream>


int main() {
    Deck deck;
    deck.shuffle();
    
    std::cout << "Drawing five cards:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        Card c = deck.draw();
        c.print();
        std::cout << " ";
    }
    std::cout << std::endl;
    
    GameManager game;
    
    game.addPlayer("Alice", 1000);
    game.addPlayer("Bob", 1000);
    
    game.playGame();
    return 0;
}
