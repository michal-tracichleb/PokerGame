#pragma once

#include "../Enumes/PlayerDecision.h"

struct Decision {
    PlayerDecision type;
    int amount = 0; // Raise/Bet
};