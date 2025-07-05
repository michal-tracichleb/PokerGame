#pragma once

#include <cstdint>
#include <string>

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

static std::string RankToString(const HandRank rank)
{
    switch (rank)
    {
    case HandRank::HighCard: return "High Card";
    case HandRank::OnePair: return "One Pair";
    case HandRank::TwoPair: return "Two Pair";
    case HandRank::ThreeOfAKind: return "Three of a Kind";
    case HandRank::Straight: return "Straight";
    case HandRank::Flush: return "Flush";
    case HandRank::FullHouse: return "Full House";
    case HandRank::FourOfAKind: return "Four of a Kind";
    case HandRank::StraightFlush: return "Straight Flush";
    case HandRank::RoyalFlush: return "Royal Flush";
    default: return "Unknown";
    }
}