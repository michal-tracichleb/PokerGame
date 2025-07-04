#pragma once

#include <vector>
#include <memory>
#include "../Core/Card.h"
#include "../Core/Player.h"

class Table {
public:
    Table();

    void SetPlayers(const std::vector<std::shared_ptr<Player>>& players);
    const std::vector<std::shared_ptr<Player>>& GetPlayers() const;

    void AddToCommunity(const Card& card);
    const std::vector<Card>& GetCommunityCards() const;

    void AddToPot(int amount);
    int GetPot() const;

    void Reset();

private:
    std::vector<std::shared_ptr<Player>> _players;
    std::vector<Card> _communityCards;
    int _pot;
};