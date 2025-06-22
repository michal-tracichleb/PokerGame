#pragma once

#include <cstdint>

enum class GamePhase : uint8_t
{
    PreFlop,
    Flop,
    Turn,
    River,
    Showdown,

    Size // Only for iteration
};