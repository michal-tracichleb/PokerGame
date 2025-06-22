#include <iostream>  
#include "HumanPlayer.h"

using namespace std;

HumanPlayer::HumanPlayer(string name, const int initialChips)
    : Player(std::move(name), initialChips)
{ }

PlayerDecision HumanPlayer::MakeDecision()
{
    cout << "\n[" << _name << "] Your chips: " << _chips << "\n";
    cout << "Pot: " << "state.pot" << ", Current bet: " << "currentBet" << "\n";
    cout << "1) Fold\n2) Call / Check\n3) Raise\n> ";

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