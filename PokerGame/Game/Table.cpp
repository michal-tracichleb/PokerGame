#include "Table.h"

Table::Table() : _pot(0) {}

void Table::SetPlayers(const std::vector<std::shared_ptr<Player>>& players) {
    _players = players;
}

const std::vector<std::shared_ptr<Player>>& Table::GetPlayers() const {
    return _players;
}

void Table::AddToCommunity(const Card& card) {
    _communityCards.push_back(card);
}

const std::vector<Card>& Table::GetCommunityCards() const {
    return _communityCards;
}

void Table::AddToPot(int amount) {
    _pot += amount;
}

int Table::GetPot() const {
    return _pot;
}

void Table::Reset() {
    _communityCards.clear();
    _pot = 0;
}