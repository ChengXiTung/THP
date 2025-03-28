#include "player.h"
#include <iostream>

Player::Player(const std::string &name, int startingChips)
    : name(name), chips(startingChips),
      hasFolded_(false), currentBet_(0), isAllIn_(false) {}


void Player::receiveCard(const Card &card) {
    hand.push_back(card);
}

void Player::clearHand() {
    hand.clear();
}

void Player::showHand() const {
    std::cout << name << "'s hand: ";
    for (const auto &card : hand) {
        card.print();
        std::cout << " ";
    }
    std::cout << std::endl;
}

int Player::getChips() const {
    return chips;  // Corrected from "money" to "chips"
}


void Player::fold() {
    hasFolded_ = true;
    std::cout << name << " has folded." << std::endl;
}


bool Player::placeBet(int amount) {
    if (hasFolded_) {
        std::cout << name << " has already folded and cannot bet." << std::endl;
        return false;
    }

    if (amount > chips) {
        std::cout << name << " does not have enough chips to bet that amount!" << std::endl;
        return false;
    }

    if (amount == chips) {
        isAllIn_ = true; // Player is now all-in
        std::cout << name << " is ALL-IN with " << amount << " chips!" << std::endl;
    } else {
        std::cout << name << " bets " << amount << " chips." << std::endl;
    }

    chips -= amount;
    currentBet_ += amount;  // Track how much they have bet this round
    return true;
}

void Player::addWinnings(int amount) {
    chips += amount;
    std::cout << name << " wins " << amount << " chips!" << std::endl;
}

std::string Player::getName() const {
    return name;
}

std::vector<Card> Player::getHand() const {
    return hand;
}

