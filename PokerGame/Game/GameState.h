#pragma once

#include <vector>
#include <cstdint>
#include "../Core/Card.h"

enum class GamePhase : uint8_t
{
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
    GamePhase phase = GamePhase::PreFlop;
};
