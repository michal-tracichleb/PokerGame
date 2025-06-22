#pragma once

#include <string>

#include "../Enumes/Color.h"
#include "../Enumes/Value.h"

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
