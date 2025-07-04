#include "GameManager.h"
#include "../Core/HumanPlayer.h"
#include "../Core/AIPlayer.h"
#include <iostream>

using namespace std;


GameManager::GameManager(const GameSettings& settings, ConsoleUI* ui)
    : _settings(settings), _ui(ui), _table(), _dealer(&_table, &_state), _gameUI(ui) {}

void GameManager::Start() {
    InitializeGame();
    GameLoop();
}

void GameManager::InitializeGame()
{
    _ui->Clear();
    vector<shared_ptr<Player>> players;
    const auto human = std::make_shared<HumanPlayer>("Player", _settings.startingChips);
    human->SetUI(&_gameUI);
    players.push_back(human);
    
    for (int i = 1; i <= _settings.numberOfOpponents; ++i) {
        string name = "Bot " + to_string(i);
        players.push_back(make_shared<AIPlayer>(name, _settings.startingChips));
    }
    
    _table.SetPlayers(players);
}

void GameManager::GameLoop()
{
    while (!IsGameOver())
    {
        ResetRound();
        _dealer.ShuffleDeck();
        _dealer.DealHoleCards();

        while (!IsRoundOver())
        {
            RenderState();
            ProcessTurn();
        }

        std::cout << "\nRound finished. Press Enter to continue.\n";
        std::cin.get();
    }
}

void GameManager::ResetRound()
{
    for (auto& player : _table.GetPlayers())
    {
        player->ResetBet();
        player->Unfold();
        player->ClearHand();
    }
    _state.currentBet = 0;
    _state.pot = 0;
    _state.phase = GamePhase::PreFlop;
    _state.communityCards.clear();
}

void GameManager::RenderState()
{
    _gameUI.RenderTable(_table, _state);
}

void GameManager::ProcessTurn()
{
    MakeDecisions();

    switch (_state.phase)
    {
    case GamePhase::PreFlop:
        _dealer.DealFlop();
        _state.phase = GamePhase::Flop;
        break;

    case GamePhase::Flop:
        _dealer.DealTurn();
        _state.phase = GamePhase::Turn;
        break;

    case GamePhase::Turn:
        _dealer.DealRiver();
        _state.phase = GamePhase::River;
        break;

    case GamePhase::River:
        _state.phase = GamePhase::Showdown;
        break;

    case GamePhase::Showdown:
        break;

    default:
        throw out_of_range("Invalid GamePhase");
    }

    std::cin.get();
}

void GameManager::MakeDecisions()
{
    auto& players = _table.GetPlayers();
    const int numPlayers = static_cast<int>(players.size());
    int currentPlayerIndex = _state.activePlayerIndex;
    int playersToAct = numPlayers;

    bool bettingRoundOngoing = true;

    while (bettingRoundOngoing)
    {
        auto& player = players[currentPlayerIndex];
        
        if (player->IsFolded() || player->GetChips() <= 0)
        {
            currentPlayerIndex = (currentPlayerIndex + 1) % numPlayers;
            --playersToAct;
            if (playersToAct <= 0)
                bettingRoundOngoing = false;
            continue;
        }

        RenderState();

        const auto decision = player->MakeDecision(_state);

        switch (decision)
        {
        case PlayerDecision::Fold:
            player->Fold();
            break;

        case PlayerDecision::Call:
        case PlayerDecision::Check:
        {
            const int toCall = _state.currentBet - player->GetCurrentBet();
            player->PayChips(toCall);
            player->SetCurrentBet(_state.currentBet);
            _state.pot += toCall;
            break;
        }

        case PlayerDecision::Raise:
        case PlayerDecision::Bet:
        {
            const int minRaise = _state.minimumRaise > 0 ? _state.minimumRaise : 10;
            const int maxRaise = player->GetChips();
            const int raiseAmount = player->GetRaiseAmount(minRaise, maxRaise);

            player->PayChips(raiseAmount);
            player->SetCurrentBet(player->GetCurrentBet() + raiseAmount);
            _state.pot += raiseAmount;

            _state.minimumRaise = raiseAmount;
            _state.currentBet = player->GetCurrentBet();
                
            playersToAct = numPlayers;
            break;
        }

        default:
            break;
        }

        currentPlayerIndex = (currentPlayerIndex + 1) % numPlayers;
        --playersToAct;
        
        if (playersToAct <= 0)
            bettingRoundOngoing = false;
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
