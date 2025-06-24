#pragma once

#include "ConsoleUI.h"
#include "Enumes/MainMenuOption.h"

class MainMenu
{
public:
    explicit MainMenu(ConsoleUI* consoleUI)
        : _consoleUI(consoleUI)
    { }
    
    MainMenuOption Run();

private:
    void Show();
    MainMenuOption _choice = MainMenuOption::Play;
    ConsoleUI* _consoleUI;
};
