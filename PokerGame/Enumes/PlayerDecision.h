#pragma once

#include <cstdint>

enum class PlayerDecision : uint8_t
{
    Fold,
    Check,
    Call,
    Bet,
    Raise,

    Size // Only for iteration
};
