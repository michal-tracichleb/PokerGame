#pragma once

#include "../Game/Table.h"
#include "../Game/GameState.h"
#include "../UI/ConsoleUI.h"
#include "../Enumes/HandRank.h"

class GameUI {
public:
    GameUI(ConsoleUI* consoleUI);

    void RenderTable(const Table& table, const GameState& state);
    PlayerDecision RenderPlayerDecisionPrompt(Player& player, int callAmount) const;
    int RenderRaiseAmountPrompt(const std::string& playerName, const int minRaise, const int maxRaise) const;
    void RenderShowdown(const std::string& playerName, HandRank bestRank) const;

private:
    ConsoleUI* _ui;
};

