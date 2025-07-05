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

    void InitializeGame();
    
    void GameLoop();
    void ResetRound();
    bool IsRoundOver();
    bool IsGameOver() const;

    void ProcessTurn();
    void MakeDecisions();
    void EvaluateShowdownWinner();
    
    void RenderState();
};
