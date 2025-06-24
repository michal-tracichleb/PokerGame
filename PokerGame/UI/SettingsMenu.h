#pragma once

#include "../Game/GameSettings.h"
#include "../Enumes/Difficulty.h"
#include "ConsoleUI.h"

class SettingsMenu
{
public:
    explicit SettingsMenu(ConsoleUI* consoleUI)
        : _consoleUI(consoleUI)
    { }
    
    GameSettings Run();

private:
    ConsoleUI* _consoleUI;

    int GetNumberOfOpponents() const;
    int GetStartingChips() const;
    Difficulty GetDifficulty() const;
};
