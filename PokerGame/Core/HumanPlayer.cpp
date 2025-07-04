#include <iostream>

#include "../UI/GameUI.h"
#include "HumanPlayer.h"

using namespace std;

HumanPlayer::HumanPlayer(string name, const int initialChips)
    : Player(std::move(name), initialChips)
{ }

void HumanPlayer::SetUI(GameUI* ui)
{
    _ui = ui;
}

PlayerDecision HumanPlayer::MakeDecision(const GameState& state)
{
    if (!_ui) {
        cerr << "GameUI not set for HumanPlayer!\n";
        return PlayerDecision::Fold;
    }

    const int callAmount = state.currentBet - GetCurrentBet();
    return _ui->RenderPlayerDecisionPrompt(*this, callAmount);
}

int HumanPlayer::GetRaiseAmount(const int minRaise, const int maxRaise) const
{
    if (!_ui) {
        std::cerr << "GameUI not set for HumanPlayer!\n";
        return minRaise;
    }

    return _ui->RenderRaiseAmountPrompt(_name, minRaise, maxRaise);
}