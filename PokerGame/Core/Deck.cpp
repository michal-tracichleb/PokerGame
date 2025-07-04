#include "Deck.h"

#include <stdexcept>

#include "../Utilities/RandomUtils.h"

using namespace std;

Deck::Deck()
{
    Initialize();
    Shuffle();
}

void Deck::Initialize()
{
    _cards.clear();
    for (int i = 0; i < static_cast<int>(Color::Size); ++i)
    {
        for (int j = 0; j < static_cast<int>(Value::Size); ++j)
        {
            _cards.emplace_back(static_cast<Color>(i), static_cast<Value>(j));
        }
    }
}

void Deck::Shuffle()
{
    const int size = static_cast<int>(_cards.size());
    for (auto& card : _cards)
    {
        const int randomIndex = Random::Range(0, size - 1);
        swap(card, _cards[randomIndex]);
    }
}

Card Deck::Deal()
{
    if (IsEmpty())
        throw out_of_range("Deck is empty");

    const Card top = _cards.back();
    _cards.pop_back();
    return top;
}

void Deck::Burn()
{
    if (IsEmpty())
        throw out_of_range("Cannot burn from empty deck");
    _cards.pop_back();
}

bool Deck::IsEmpty() const
{
    return _cards.empty();
}