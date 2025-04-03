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
    // Check normal straight
    if (ranks[4] - ranks[0] == 4) return true;
    // Check Ace-low straight
    if (ranks == std::vector<int>{2, 3, 4, 5, 14}) return true;
    return false;
}

int HandEvaluator::evaluateHand(const std::vector<Card>& sevenCards) {
    int bestRank = HIGH_CARD;
    
    // Generate all 21 possible 5-card combinations
    for (int i=0; i<7; ++i) {
        for (int j=i+1; j<7; ++j) {
            std::vector<Card> fiveCards;
            for (int k=0; k<7; ++k) {
                if (k != i && k != j) fiveCards.push_back(sevenCards[k]);
            }
            int currentRank = evaluateFiveCards(fiveCards);
            if (currentRank > bestRank) bestRank = currentRank;
        }
    }
    return bestRank;
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

// Evaluates a 5-card hand and returns its rank
int HandEvaluator::evaluateFiveCards(const std::vector<Card>& fiveCards) {
    if (fiveCards.size() != 5) return HIGH_CARD;

    // Count occurrences of each rank
    std::map<int, int> rankCount;
    std::vector<int> ranks;
    for (const auto& card : fiveCards) {
        rankCount[static_cast<int>(card.rank)]++;
        ranks.push_back(static_cast<int>(card.rank));
    }

    // Check for pairs, three-of-a-kind, etc.
    int pairs = 0, threeOfKind = 0, fourOfKind = 0;
    for (const auto& pair : rankCount) {
        if (pair.second == 2) pairs++;
        if (pair.second == 3) threeOfKind++;
        if (pair.second == 4) fourOfKind++;
    }

    bool flush = isFlush(fiveCards);
    bool straight = isStraight(ranks);

    // Determine hand rank (same as your previous code)
    if (flush && straight && *std::max_element(ranks.begin(), ranks.end()) == 14) 
        return ROYAL_FLUSH;
    if (flush && straight) return STRAIGHT_FLUSH;
    if (fourOfKind) return FOUR_OF_A_KIND;
    // ... rest of your existing logic ...
    
    return HIGH_CARD;
}
