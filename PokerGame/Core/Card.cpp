﻿#include <string>

#include "Card.h"

using namespace std;

bool Card::operator<(const Card& other) const
{
    if (_value != other._value)
        return _value < other._value;
    return _color > other._color;
}

bool Card::operator>(const Card& other) const {
    if (_value != other._value)
        return _value > other._value;
    return _color < other._color;
}

bool Card::operator==(const Card& other) const
{
    return _value == other._value && _color == other._color;
}

bool Card::operator!=(const Card& other) const {
    return !(*this == other);
}

string Card::ToString() const
{
    static const char* colors[] = {u8"\u2665", u8"\u2660", u8"\u2666", u8"\u2663"}; // ♥ ♠ ♦ ♣
    static const char* values[] = {
        " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10",
        " J", " Q", " K", " A"
    };

    return "[" + string(colors[static_cast<int>(_color)]) + string(values[static_cast<int>(_value)]) + "]";
}