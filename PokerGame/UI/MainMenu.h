#pragma once

#include "ConsoleUI.h"
#include "Enumes/MainMenuOption.h"

class MainMenu
{
public:
    MainMenu(ConsoleUI* consoleUI)
        : _consoleUI(consoleUI)
    { }
    
    MainMenuOption Run();

private:
    void Show();
    MainMenuOption _choice;
    ConsoleUI* _consoleUI;
};
