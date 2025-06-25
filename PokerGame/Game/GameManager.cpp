#include "GameManager.h"
#include <iostream>

GameManager::GameManager(const GameSettings& settings, ConsoleUI* ui)
    : _settings(settings), _ui(ui) {}//, _dealer(settings), _table(settings) {}

void GameManager::Start() {
    InitializeGame();
    GameLoop();
}

void GameManager::InitializeGame()
{
    _ui->Clear();
    std::cout << "Starting Texas Hold'em with " 
              << _settings.numberOfOpponents << " opponents...\n";
    // TODO: create players, shuffle deck, etc.
}

void GameManager::GameLoop() const
{
    while (!IsGameOver()) {
        RenderState();
        ProcessTurn();
        // TODO: resolve round, handle folding, deal new cards
    }
}

void GameManager::RenderState() const
{
    _ui->Clear();
    std::cout << "Round in progress...\n";
    // TODO: draw table, cards, player chips etc.
}

void GameManager::ProcessTurn() const
{
    std::cout << "Processing next move...\n";
    // TODO: ask human/AI players for decisions
}

bool GameManager::IsGameOver() const
{
    std::cout << "Game over...\n";
    std::cin.get();
    // TODO: e.g., only one player left with chips
    return true;
}
