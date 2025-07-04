#pragma once

#include "../Core/Deck.h"
#include "../Game/Table.h"
#include "GameState.h"

class Dealer {
public:
    Dealer(Table* table, GameState* state);

    void ShuffleDeck();
    void DealHoleCards();
    void DealFlop();
    void DealTurn();
    void DealRiver();

private:
    Deck _deck;
    Table* _table;
    GameState* _state;
};
