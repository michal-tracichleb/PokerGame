#pragma once

#include "../Game/Table.h"
#include "../Game/GameState.h"
#include "../UI/ConsoleUI.h"

class GameUI {
public:
    GameUI(ConsoleUI* consoleUI);

    void RenderTable(const Table& table, const GameState& state);
    PlayerDecision RenderPlayerDecisionPrompt(Player& player, int callAmount) const;
    void RenderShowdown(const Table& table, const GameState& state);

private:
    ConsoleUI* _ui;
};
