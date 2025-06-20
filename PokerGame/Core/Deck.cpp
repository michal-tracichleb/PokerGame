#include "Deck.h"
#include <random>

using namespace std;

Deck::Deck()
{
    Initialize();
}


void Deck::Initialize()
{
    int cardsCounter = 0;
    for (int i = 0; i < static_cast<int>(Color::Size); ++i)
    {
        for (int j = 0; j < static_cast<int>(Value::Size); ++j)
        {
            _cards[cardsCounter] = Card(static_cast<Color>(i), static_cast<Value>(j));
            cardsCounter++;
        }
    }
}

void Deck::Shuffle()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, DeckSize - 1);
    
    for (auto& card : _cards)
    {
        const int randomIndex = dist(gen);
        swap(card, _cards[randomIndex]);
    }
}

Card Deck::Deal(const int number) const
{
    return _cards[number];
}