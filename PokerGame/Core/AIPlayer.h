#pragma once

#include "Player.h"

class AIPlayer final : public Player
{
public:
    AIPlayer(std::string name, int initialChips);

    PlayerDecision MakeDecision(const GameState& state) override;
    bool IsAI() const override { return true; }
};