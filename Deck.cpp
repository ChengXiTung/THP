#include "deck.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <string>

Deck::Deck() {
    reset();  // Initialize deck
}

void Deck::reset() {
    cards.clear();
    for (int s = 0; s < 4; ++s) {
        for (int r = 2; r <= 14; ++r) {
            cards.push_back({static_cast<Rank>(r), static_cast<Suit>(s)});
        }
    }
    shuffle();
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::draw() {
    if (cards.empty()) {
        std::cerr << "Deck is empty!" << std::endl;
        return {Rank::Ace, Suit::Spades};  // Return a default card
    }
    Card top = cards.back();
    cards.pop_back();
    return top;
}

void Deck::burnCard() {
    if (!cards.empty()) {
        cards.pop_back(); // Burn the top card
    }
}

void Deck::printDeck() {
    for (const auto &card : cards) {
        std::cout << card.toString() << std::endl;
    }
}
