#include "Table.h"

void Table::SetPlayers(const std::vector<std::shared_ptr<Player>>& players) {
    _players = players;
}

const std::vector<std::shared_ptr<Player>>& Table::GetPlayers() const {
    return _players;
}