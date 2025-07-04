#pragma once

#include "../Core/Deck.h"
#include "../Game/Table.h"

class Dealer {
public:
    Dealer(Table* table);

    void ShuffleDeck();
    void DealHoleCards();
    void DealFlop();
    void DealTurn();
    void DealRiver();

private:
    Deck _deck;
    Table* _table;
};