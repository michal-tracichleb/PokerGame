#include "GameManager.h"
#include "../Core/HumanPlayer.h"
#include "../Core/AIPlayer.h"
#include <iostream>

using namespace std;


GameManager::GameManager(const GameSettings& settings, ConsoleUI* ui)
    : _settings(settings), _ui(ui), _table(), _dealer(&_table) {}

void GameManager::Start() {
    InitializeGame();
    GameLoop();
}

void GameManager::InitializeGame()
{
    _ui->Clear();
    cout << "Starting Texas Hold'em with "
              << _settings.numberOfOpponents << " opponents...\n";

    vector<shared_ptr<Player>> players;
    players.push_back(std::make_shared<HumanPlayer>("Player", _settings.startingChips));
    
    for (int i = 1; i <= _settings.numberOfOpponents; ++i) {
        string name = "Bot " + to_string(i);
        players.push_back(make_shared<AIPlayer>(name, _settings.startingChips));
    }
    
    _table.SetPlayers(players);

    _dealer.ShuffleDeck();
    _dealer.DealHoleCards();

    std::cin.get();
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
