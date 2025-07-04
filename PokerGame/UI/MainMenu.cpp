#include <vector>
#include <string>

#include "MainMenu.h"
#include "ConsoleUI.h"
#include "Enumes/MainMenuOption.h"

using namespace std;

MainMenuOption MainMenu::Run()
{
    Show();
    return _choice;
}

void MainMenu::Show()
{
    _consoleUI->Clear();

    const vector<string> options = {
        "Play",
        "Rank",
        "End Game"
    };

    const int selection = _consoleUI->GetArrowSelection(options, 0, 0);

    switch (selection)
    {
    case 0:
        _choice = MainMenuOption::Play;
        break;
    case 1:
        _choice = MainMenuOption::Rank;
        break;
    case 2:
        _choice = MainMenuOption::Exit;
        exit(0);
    default:
        _choice = MainMenuOption::Exit;
        break;
    }
}
