#include "GameManager.h"
#include "../Core/HumanPlayer.h"
#include "../Core/AIPlayer.h"
#include <iostream>

using namespace std;


GameManager::GameManager(const GameSettings& settings, ConsoleUI* ui)
    : _settings(settings), _ui(ui), _table(), _dealer(&_table, &_state) {}

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
    _state.phase = GamePhase::PreFlop;
}

void GameManager::GameLoop()
{
    while (!IsGameOver())
    {
        std::cout << "Starting new round...\n";
        _dealer.ShuffleDeck();
        _dealer.DealHoleCards();
        _state.phase = GamePhase::PreFlop;
        _state.communityCards.clear();
        _state.pot = 0;

        while (!IsRoundOver())
        {
            RenderState();
            ProcessTurn();
        }

        std::cout << "\nRound finished. Press Enter to continue.\n";
        std::cin.get();
    }
}

void GameManager::RenderState() const
{
    std::cout << "Round in progress...\n";
    // TODO: draw table, cards, player chips etc.
}

void GameManager::ProcessTurn()
{
    switch (_state.phase)
    {
    case GamePhase::PreFlop:
        std::cout << "Processing Pre-Flop decisions...\n";
        // TODO: logika betowania
        _dealer.DealFlop();
        _state.phase = GamePhase::Flop;
        std::cin.get();
        break;

    case GamePhase::Flop:
        std::cout << "Processing Flop decisions...\n";
        _dealer.DealTurn();
        _state.phase = GamePhase::Turn;
        std::cin.get();
        break;

    case GamePhase::Turn:
        std::cout << "Processing Turn decisions...\n";
        _dealer.DealRiver();
        _state.phase = GamePhase::River;
        std::cin.get();
        break;

    case GamePhase::River:
        std::cout << "Processing River decisions...\n";
        _state.phase = GamePhase::Showdown;
        std::cin.get();
        break;

    case GamePhase::Showdown:
        std::cout << "\nShowdown! (Winner TBD)\n";
        std::cin.get();
        break;
        
    default:
        throw out_of_range("Invalid GamePhase");
    }
}

bool GameManager::IsRoundOver() const
{
    return _state.phase == GamePhase::Showdown;
}

bool GameManager::IsGameOver() const
{
    int playersWithChips = 0;
    for (const auto& player : _table.GetPlayers()) {
        if (player->GetChips() > 0)
            playersWithChips++;
    }

    return playersWithChips <= 1;
}
