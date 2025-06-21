#include "Player.h"

using namespace std;

Player::Player(string name, const int initialChips)
    : _name(std::move(name)), _chips(initialChips), _folded(false)
{
}

const string& Player::GetName() const {
    return _name;
}

int Player::GetChips() const {
    return _chips;
}

void Player::AddChips(const int amount) {
    _chips += amount;
}

bool Player::RemoveChips(const int amount) {
    if (_chips >= amount) {
        _chips -= amount;
        return true;
    }
    return false;
}

void Player::AddCard(const Card& card) {
    _hand.push_back(card);
}

void Player::ClearHand() {
    _hand.clear();
}

const vector<Card>& Player::GetHand() const {
    return _hand;
}

bool Player::IsFolded() const {
    return _folded;
}

void Player::Fold() {
    _folded = true;
}

void Player::Unfold() {
    _folded = false;
}
