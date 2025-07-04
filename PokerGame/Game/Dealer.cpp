#include "Dealer.h"
#include "../Core/Player.h"
#include <vector>
#include <memory>


Dealer::Dealer(Table* table)
    : _table(table)
{
}

void Dealer::ShuffleDeck() {
    _deck.Initialize();
    _deck.Shuffle();
}

void Dealer::DealHoleCards() {
    const auto& players = _table->GetPlayers();
    for (int i = 0; i < 2; ++i) {
        for (auto& player : players) {
            player->AddCard(_deck.Deal());
        }
    }
}

void Dealer::DealFlop() {
    _deck.Burn();
    for (int i = 0; i < 3; ++i) {
        _table->AddToCommunity(_deck.Deal());
    }
}

void Dealer::DealTurn() {
    _deck.Burn();
    _table->AddToCommunity(_deck.Deal());
}

void Dealer::DealRiver() {
    _deck.Burn();
    _table->AddToCommunity(_deck.Deal());
}
