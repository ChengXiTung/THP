#include "GameManager.h"
#include "HandEvaluator.h"
#include <iostream>

GameManager::GameManager() : pot(0) {}

void GameManager::addPlayer(const std::string& name, int chips) {
    players.emplace_back(name, chips);
}

void GameManager::dealHoleCards() {
    for (int i = 0; i < 2; ++i) { // Each player gets 2 cards
        for (auto &player : players) {
            player.receiveCard(deck.draw());
        }
    }
}

void GameManager::dealCommunityCards(int count) {
    deck.burnCard();  // Burn a card before dealing
    for (int i = 0; i < count; ++i) {
        communityCards.push_back(deck.draw());
    }
}

void GameManager::showCommunityCards() const {
    std::cout << "Community Cards: ";
    for (const auto &card : communityCards) {
        card.print();
        std::cout << " ";
    }
    std::cout << std::endl;
}

void GameManager::startBettingRound() {
    int minBet = 50;
    for (auto &player : players) {
        if (player.hasFolded()) {
            continue;  // Skip players who have folded
        }
        if (player.getChips() >= minBet) {
            player.placeBet(minBet);
            pot += minBet;
        }
    }
    std::cout << "Total pot: " << pot << " chips\n";
}

void GameManager::determineWinner() {
    std::cout << "Evaluating hands...\n";

    int bestRank = 0;
    std::string bestPlayer;
    
    for (auto &player : players) {
        std::vector<Card> fullHand = player.getHand(); // Get player's hole cards
        fullHand.insert(fullHand.end(), communityCards.begin(), communityCards.end()); // Add community cards

        int rank = HandEvaluator::evaluateHand(fullHand);
        std::cout << player.getName() << " has: " << HandEvaluator::getHandRankName(rank) << "\n";

        if (rank > bestRank) {
            bestRank = rank;
            bestPlayer = player.getName();
        }
    }

    std::cout << bestPlayer << " wins the pot with " << HandEvaluator::getHandRankName(bestRank) << "!\n";
}

void GameManager::playGame() {
    deck.shuffle();
    dealHoleCards();
    
    std::cout << "Dealing hole cards...\n";
    for (auto &player : players) {
        player.showHand();
    }

    std::cout << "\nStarting Pre-flop Betting...\n";
    startBettingRound();

    std::cout << "\nDealing Flop...\n";
    dealCommunityCards(3);
    showCommunityCards();

    std::cout << "\nStarting Flop Betting...\n";
    startBettingRound();

    std::cout << "\nDealing Turn...\n";
    dealCommunityCards(1);
    showCommunityCards();

    std::cout << "\nStarting Turn Betting...\n";
    startBettingRound();

    std::cout << "\nDealing River...\n";
    dealCommunityCards(1);
    showCommunityCards();

    std::cout << "\nFinal Betting Round...\n";
    startBettingRound();

    std::cout << "\nDetermining Winner...\n";
    determineWinner();
}
