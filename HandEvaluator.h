#ifndef HANDEVALUATOR_H
#define HANDEVALUATOR_H

#include "card.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>

class HandEvaluator {
public:
    static int evaluateHand(const std::vector<Card>& hand);
    static std::string getHandRankName(int rank);
};

#endif
