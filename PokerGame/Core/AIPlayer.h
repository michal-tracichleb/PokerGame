#pragma once

#include "Player.h"

class AIPlayer final : public Player
{
public:
    AIPlayer(std::string name, int initialChips);

    bool IsAI() const override { return true; }
    PlayerDecision MakeDecision(const GameState& state) override;
    int GetRaiseAmount(int minRaise, int maxRaise) const override;
};