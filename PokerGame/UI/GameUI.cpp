#include "GameUI.h"
#include "../Enumes/PlayerDecision.h"
#include <iostream>

using namespace std;

GameUI::GameUI(ConsoleUI* consoleUI)
    : _ui(consoleUI) {}

void GameUI::RenderTable(const Table& table, const GameState& state)
{
    _ui->Clear();
    int y = 1;

    _ui->DrawTextWithColor(2, y++, "=== Community Cards ===", TextColor::Cyan);
    string cards;
    for (const auto& card : state.communityCards)
        cards += card.ToString() + " ";
    _ui->DrawTextWithColor(4, y++, cards, TextColor::Default);
    y++;

    _ui->DrawTextWithColor(2, y++, "=== Players ===", TextColor::Green);

    for (const auto& player : table.GetPlayers())
    {
        string status = player->IsFolded() ? " (FOLDED)" : "";
        TextColor statusColor = player->IsFolded() ? TextColor::Red : TextColor::Default;
        string info = player->GetName() + " | Chips: " +
                           to_string(player->GetChips()) + status;
        _ui->DrawTextWithColor(4, y++, info, statusColor);

        string hand = "Cards: ";
        if (state.phase != GamePhase::Showdown
            && player->IsAI()) {
           hand += "[X X] [X X]";
        } else {
            for (const auto& card : player->GetHand())
                hand += card.ToString() + " ";
        }
        _ui->DrawTextWithColor(6, y++, hand, TextColor::Default);

        y++;
    }

    string potLine = "Pot: " + to_string(state.pot);
    _ui->DrawTextWithColor(2, y++, potLine, TextColor::Yellow);

    string phase;
    switch (state.phase) {
    case GamePhase::PreFlop: phase = "Pre-Flop"; break;
    case GamePhase::Flop:    phase = "Flop"; break;
    case GamePhase::Turn:    phase = "Turn"; break;
    case GamePhase::River:   phase = "River"; break;
    case GamePhase::Showdown:phase = "Showdown"; break;
    }

    _ui->DrawTextWithColor(2, y++, "Phase: " + phase, TextColor::Magenta);
}

PlayerDecision GameUI::RenderPlayerDecisionPrompt(Player& player, const int callAmount) const
{
    int y = 2;

    _ui->DrawTextWithColor(35, y++, "Your turn, " + player.GetName(), TextColor::Yellow);
    _ui->DrawTextWithColor(35, y++, "Chips: " + to_string(player.GetChips()), TextColor::Default);

    string hand = "Cards: ";
    for (const auto& card : player.GetHand())
        hand += card.ToString() + " ";
    _ui->DrawTextWithColor(35, y++, hand, TextColor::Default);

    y++;

    const vector<string> options = {
        "Fold",
        "Call " + to_string(callAmount),
        "Raise"
    };

    const int choice = _ui->GetArrowSelection(options, 35, y);
    switch (choice) {
    case 0: return PlayerDecision::Fold;
    case 1: return PlayerDecision::Call;
    case 2: return PlayerDecision::Raise;
    default: return PlayerDecision::Fold;
    }
}

int GameUI::RenderRaiseAmountPrompt(const std::string& playerName, const int minRaise, const int maxRaise) const
{
    _ui->DrawTextWithColor(35, 10, playerName + ", enter your raise amount.", TextColor::Yellow);
    _ui->DrawTextWithColor(35, 12, "Minimum: " + std::to_string(minRaise), TextColor::Default);
    _ui->DrawTextWithColor(35, 13, "Maximum: " + std::to_string(maxRaise), TextColor::Default);
    _ui->DrawTextWithColor(35, 15, "> ", TextColor::Default);

    int amount;
    std::cin >> amount;
    
    if (amount < minRaise)
        amount = minRaise;
    else if (amount > maxRaise)
        amount = maxRaise;

    return amount;
}

void GameUI::RenderShowdown(const std::string& playerName, const HandRank bestRank) const
{
    int y = 1;
    
    _ui->DrawTextWithColor(35, y++, "Showdown!", TextColor::Yellow);
    _ui->DrawTextWithColor(35, y++, "Winner: " + playerName, TextColor::Green);
    _ui->DrawTextWithColor(35, y++, "Winning Hand: " + RankToString(bestRank), TextColor::Cyan);
}