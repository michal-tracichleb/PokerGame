#pragma once

#include <vector>
#include <utility>

#include "Card.h"
#include "../Enumes/HandRank.h"

class HandEvaluator {
public:
    static std::pair<HandRank, std::vector<Card>> Evaluate(const std::vector<Card>& cards);
};