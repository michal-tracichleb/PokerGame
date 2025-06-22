#pragma once
#include "Player.h"

class HumanPlayer final : public Player
{
public:
    HumanPlayer(std::string name, const int initialChips);

    PlayerDecision MakeDecision() override;
};
