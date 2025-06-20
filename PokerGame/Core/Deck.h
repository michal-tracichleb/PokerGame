#pragma once

#include "Card.h"

constexpr int DeckSize = static_cast<int>(Color::Size) * static_cast<int>(Value::Size);

class Deck
{
public:
    Deck();
    
    void Initialize();
    void Shuffle();
    Card Deal(int number) const;

private:
    Card _cards[DeckSize];
};
