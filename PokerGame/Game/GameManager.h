#pragma once

#include "GameSettings.h"
#include "../UI/ConsoleUI.h"
#include "../UI/GameUI.h"
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
    GameUI _gameUI;

    GameState _state;
    Table _table;
    Dealer _dealer;

    void GameLoop();
    void InitializeGame();
    void ProcessTurn();
    void RenderState();
    bool IsRoundOver() const;
    bool IsGameOver() const;
};
