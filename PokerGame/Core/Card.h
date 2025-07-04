#pragma once

#include <string>

#include "../Enumes/Color.h"
#include "../Enumes/Value.h"

class Card
{
public:
    Card() = default;
    Card(const Card&) = default;   
    Card(const Color color, const Value value) : _color(color), _value(value) {}
    
    Color GetColor() const { return _color; }
    Value GetValue() const { return _value; }

    bool operator<(const Card& other) const;
    bool operator>(const Card& other) const;
    bool operator==(const Card& other) const;
    bool operator!=(const Card& other) const;

    Card& operator=(const Card&) = default;
    
    std::string ToString() const;
    
private:
    Color _color;
    Value _value;
};
