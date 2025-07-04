#pragma once

#include <vector>
#include "Card.h"

class Deck
{
public:
    Deck();

    void Initialize();
    void Shuffle();
    Card Deal();
    void Burn();
    bool IsEmpty() const;

private:
    std::vector<Card> _cards;
};
