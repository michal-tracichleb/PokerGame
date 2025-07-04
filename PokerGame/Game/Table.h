#pragma once

#include <vector>
#include <memory>
#include "../Core/Player.h"

class Table {
public:
    Table() = default;

    void SetPlayers(const std::vector<std::shared_ptr<Player>>& players);
    const std::vector<std::shared_ptr<Player>>& GetPlayers() const;

private:
    std::vector<std::shared_ptr<Player>> _players;
};