#pragma once

#include "Enumes/MainMenuOption.h"

class MainMenu
{
public:
    MainMenuOption Run();

private:
    void Show();
    MainMenuOption _choice;
};
