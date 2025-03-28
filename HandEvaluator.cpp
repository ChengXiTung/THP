#include "HandEvaluator.h"
#include <algorithm>
#include <map>
#include <iostream>

enum HandRank {
    HIGH_CARD = 1,
    ONE_PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH
};

// Helper function to check if the hand is a flush
bool isFlush(const std::vector<Card>& hand) {
    Suit firstSuit = hand[0].suit;
    for (const auto& card : hand) {
        if (card.suit != firstSuit) return false;
    }
    return true;
}

// Helper function to check if the hand is a straight
bool isStraight(std::vector<int> ranks) {
    std::sort(ranks.begin(), ranks.end());
    for (size_t i = 0; i < ranks.size() - 1; ++i) {
        if (ranks[i] + 1 != ranks[i + 1]) return false;
    }
    return true;
}

// Main hand evaluation function
int HandEvaluator::evaluateHand(const std::vector<Card>& hand) {
    if (hand.size() != 7) return HIGH_CARD;  // Must have 7 cards

    // Count occurrences of each rank
    std::map<int, int> rankCount;
    std::vector<int> ranks;
    for (const auto& card : hand) {
        rankCount[static_cast<int>(card.rank)]++;
        ranks.push_back(static_cast<int>(card.rank));
    }

    // Check for pairs, three-of-a-kind, and four-of-a-kind
    int pairs = 0, threeOfKind = 0, fourOfKind = 0;
    for (const auto& pair : rankCount) {
        if (pair.second == 2) pairs++;
        if (pair.second == 3) threeOfKind++;
        if (pair.second == 4) fourOfKind++;
    }

    bool flush = isFlush(hand);
    bool straight = isStraight(ranks);

    if (flush && straight && *std::max_element(ranks.begin(), ranks.end()) == 14) return ROYAL_FLUSH;
    if (flush && straight) return STRAIGHT_FLUSH;
    if (fourOfKind) return FOUR_OF_A_KIND;
    if (threeOfKind && pairs) return FULL_HOUSE;
    if (flush) return FLUSH;
    if (straight) return STRAIGHT;
    if (threeOfKind) return THREE_OF_A_KIND;
    if (pairs == 2) return TWO_PAIR;
    if (pairs == 1) return ONE_PAIR;

    return HIGH_CARD;
}

// Returns a string name for each hand rank
std::string HandEvaluator::getHandRankName(int rank) {
    switch (rank) {
        case ROYAL_FLUSH: return "Royal Flush";
        case STRAIGHT_FLUSH: return "Straight Flush";
        case FOUR_OF_A_KIND: return "Four of a Kind";
        case FULL_HOUSE: return "Full House";
        case FLUSH: return "Flush";
        case STRAIGHT: return "Straight";
        case THREE_OF_A_KIND: return "Three of a Kind";
        case TWO_PAIR: return "Two Pair";
        case ONE_PAIR: return "One Pair";
        default: return "High Card";
    }
}
