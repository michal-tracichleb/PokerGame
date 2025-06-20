#pragma once
#include <cstdint>
#include <string>

enum class Color : uint8_t
{
    Hearts,
    Spades,
    Diamonds,
    Clubs,

    Size // Only for iteration
};

enum class Value : uint8_t
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,

    Size // Only for iteration
};

class Card
{
public:
    Card() = default;
    Card(const Color color, const Value value) : _color(color), _value(value) {}
    
    Color GetColor() const { return _color; }
    Value GetValue() const { return _value; }
    
    std::string ToString() const;
    
private:
    Color _color;
    Value _value;
};
