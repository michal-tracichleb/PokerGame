#include <iostream>

#include "HumanPlayer.h"

using namespace std;

HumanPlayer::HumanPlayer(string name, const int initialChips)
    : Player(std::move(name), initialChips)
{ }

PlayerDecision HumanPlayer::MakeDecision(const GameState& state)
{
    cout << "\n[" << _name << "] Your chips: " << _chips << "\n";
    cout << "Pot: " << state.pot << ", Current bet: " << state.currentBet << "\n";
    cout << "Phase: ";

    switch (state.phase)
    {
        case GamePhase::PreFlop:
            cout << "Pre-Flop";
            break;
        case GamePhase::Flop:
            cout << "Flop";
            break;
        case GamePhase::Turn:
            cout << "Turn";
            break;
        case GamePhase::River:
            cout << "River";
            break;
        case GamePhase::Showdown:
            cout << "Showdown";
            break;
        default:
            cout << "???";
            break;
    }

    cout << "\n1) Fold\n2) Call / Check\n3) Raise\n> ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        return PlayerDecision::Fold;
    case 2:
        return PlayerDecision::Call;
    case 3:
        {
            cout << "Raise amount: ";
            int amount;
            cin >> amount;
            return PlayerDecision::Raise;
        }
    default:
        cout << "Invalid choice. Folding by default.\n";
        return PlayerDecision::Fold;
    }
}