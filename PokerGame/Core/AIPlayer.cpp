#include "../Utilities/RandomUtils.h"
#include "AIPlayer.h"

using namespace std;

AIPlayer::AIPlayer(string name, const int initialChips)
    : Player(std::move(name), initialChips)
{}

PlayerDecision AIPlayer::MakeDecision(const GameState& state)
{
    if (_folded || _chips <= 0)
        return PlayerDecision::Fold;

    const int r = Random::Range(0, 99);

    if (r < 20)
        return PlayerDecision::Fold;
    
    if (r < 70)
        return PlayerDecision::Call;

    return PlayerDecision::Raise;
}