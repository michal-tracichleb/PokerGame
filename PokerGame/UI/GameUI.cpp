#include "GameUI.h"
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
    _ui->DrawTextWithColor(4, y++, cards, TextColor::White);
    y++;

    _ui->DrawTextWithColor(2, y++, "=== Players ===", TextColor::Green);

    for (const auto& player : table.GetPlayers())
    {
        string status = player->IsFolded() ? " (FOLDED)" : "";
        string info = player->GetName() + " | Chips: " +
                           to_string(player->GetChips()) + status;
        _ui->DrawTextWithColor(4, y++, info, TextColor::White);

        string hand = "Cards: ";
        if (player->IsAI()) {
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
