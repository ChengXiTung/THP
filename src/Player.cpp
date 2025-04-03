// Player.cpp
#include "Player.h"
#include <iostream>

Player::Player(const std::string &name, int startingChips)
    : name(name), chips(startingChips), isAllIn(false), hasFolded(false), currentBet(0) {}

void Player::receiveCard(const Card &card) {
    hand.push_back(card);
}

void Player::clearHand() {
    hand.clear();
}

void Player::showHand() const {
    std::cout << name << "'s hand: " << std::endl;
    for (const auto &card : hand) {
        card.print();
        std::cout << " ";
    }
    std::cout << std::endl;
}

int Player::getChips() const {
    return chips;
}

void Player::fold() {
    hasFolded = true;
    std::cout << name << " has folded." << std::endl;
}

bool Player::placeBet(int amount) {
    if (hasFolded) {
        std::cout << name << " has already folded and cannot bet." << std::endl;
        return false;
    }

    if (amount > chips) {
        std::cout << name << " does not have enough chips to bet that amount!" << std::endl;
        return false;
    }

    if (amount == chips) {
        isAllIn = true; // Player is now all-in
        std::cout << name << " is ALL-IN with " << amount << " chips!" << std::endl;
    } else {
        std::cout << name << " bets " << amount << " chips." << std::endl;
    }

    chips -= amount;
    currentBet += amount;  // Track how much they have bet this round
    return true;
}

bool Player::getHasFolded() const {
    return hasFolded;
}

void Player::setHasFolded(bool folded) {
    hasFolded = folded;
}

int Player::getCurrentBet() const {
    return currentBet;
}

void Player::setCurrentBet(int bet) {
    currentBet = bet;
}

bool Player::getIsAllIn() const {
    return isAllIn;
}

void Player::setIsAllIn(bool allIn) {
    isAllIn = allIn;
}