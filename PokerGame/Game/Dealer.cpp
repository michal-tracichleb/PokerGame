#include "Dealer.h"
#include "../Core/Player.h"
#include <vector>
#include <memory>

Dealer::Dealer(Table* table, GameState* state)
    : _table(table), _state(state)
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
        _state->communityCards.push_back(_deck.Deal());
    }
}

void Dealer::DealTurn() {
    _deck.Burn();
    _state->communityCards.push_back(_deck.Deal());
}

void Dealer::DealRiver() {
    _deck.Burn();
    _state->communityCards.push_back(_deck.Deal());
}
