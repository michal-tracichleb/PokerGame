#pragma once

#include "../Enumes/Difficulty.h"

struct GameSettings
{
    int numberOfOpponents = 1;
    int startingChips = 1000;
    Difficulty difficulty = Difficulty::Normal;
};
