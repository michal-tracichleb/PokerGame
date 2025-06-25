#pragma once

#include "GameSettings.h"
#include "../UI/ConsoleUI.h"
#include "GameState.h"
#include "Dealer.h"
#include "Table.h"

class GameManager {
public:
    GameManager(const GameSettings& settings, ConsoleUI* ui);

    void Start();

private:
    GameSettings _settings;
    ConsoleUI* _ui;

    GameState _state;
    Dealer _dealer;
    Table _table;

    void GameLoop() const;
    void InitializeGame();
    void ProcessTurn() const;
    void RenderState() const;
    bool IsGameOver() const;
};
