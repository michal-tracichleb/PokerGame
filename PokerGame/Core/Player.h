#pragma once

#include <vector>
#include <string>

#include "Card.h"
#include "../Game/Decision.h"
#include "../Game/GameState.h"

class Player
{
public:
    Player(std::string name, int initialChips);
    virtual ~Player() = default;

    const std::string& GetName() const;
    int GetChips() const;
    void AddChips(int amount);
    bool RemoveChips(int amount);

    void AddCard(const Card& card);
    void ClearHand();
    const std::vector<Card>& GetHand() const;

    bool IsFolded() const;
    void Fold();
    void Unfold();

    int GetCurrentBet() const;
    void SetCurrentBet(int newBet);
    void PayChips(int amount);
    void ResetBet();

    virtual bool IsAI() const { return false; }
    virtual PlayerDecision MakeDecision(const GameState& state) = 0;
    virtual int GetRaiseAmount(int minRaise, int maxRaise) const = 0;

protected:
    std::string _name;
    int _chips;
    std::vector<Card> _hand;
    bool _folded;

private:
    int _currentBet = 0;
};
