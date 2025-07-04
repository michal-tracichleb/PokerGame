#pragma once

#include "../Game/Table.h"
#include "../Game/GameState.h"
#include "../UI/ConsoleUI.h"

class GameUI {
public:
    GameUI(ConsoleUI* consoleUI);

    void RenderTable(const Table& table, const GameState& state);
    void RenderPlayerDecisionPrompt(const std::shared_ptr<Player>& player);
    void RenderShowdown(const Table& table, const GameState& state);

private:
    ConsoleUI* _ui;
};
