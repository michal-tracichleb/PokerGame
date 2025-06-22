#pragma once

#include <cstdint>

enum class HandRank : uint8_t {
    HighCard,
    OnePair,
    TwoPair,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush,

    Size // Only for iteration
};
