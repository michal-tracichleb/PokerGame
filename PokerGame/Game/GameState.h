#pragma once

#include <vector>
#include "../Core/Card.h"

class Card;

struct GameState {
    std::vector<Card> communityCards;
    int pot = 0;
    int currentBet = 0;
    int minimumRaise = 0;
    int activePlayerIndex = 0;
};
