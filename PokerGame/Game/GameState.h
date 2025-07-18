﻿#pragma once

#include <vector>

#include "../Core/Card.h"
#include "../Enumes/GamePhase.h"

struct GameState {
    std::vector<Card> communityCards;
    int pot = 0;
    int currentBet = 0;
    int activePlayerIndex = 0;
    GamePhase phase = GamePhase::PreFlop;
};
