#pragma once

#include <vector>
#include "../Core/Card.h"

class Card;

enum class Phase : int8_t{
    PreFlop,
    Flop,
    Turn,
    River,
    Showdown,

    Size // Only for iteration
};

struct GameState {
    std::vector<Card> communityCards;
    int pot = 0;
    int currentBet = 0;
    int minimumRaise = 0;
    int activePlayerIndex = 0;
    Phase phase = Phase::Size;
};
