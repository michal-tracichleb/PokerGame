#pragma once
#include "Player.h"
#include "../Game/GameState.h"

class HumanPlayer final : public Player
{
public:
    HumanPlayer(std::string name, const int initialChips);

    PlayerDecision MakeDecision(const GameState& state) override;
};
