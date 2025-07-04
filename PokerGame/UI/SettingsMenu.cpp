#include <vector>

#include "SettingsMenu.h"

using namespace std;

GameSettings SettingsMenu::Run()
{
    _consoleUI->Clear();

    GameSettings settings;

    settings.numberOfOpponents = GetNumberOfOpponents();
    settings.startingChips = GetStartingChips();
    settings.difficulty = GetDifficulty();

    return settings;
}

int SettingsMenu::GetNumberOfOpponents() const
{
    _consoleUI->Clear();

    const vector<string> options = { "1", "2", "3", "4", "5", "6", "7" };
    _consoleUI->DrawTextWithColor(0, 0, "Select number of opponents:");
    const int choice = _consoleUI->GetArrowSelection(options, 0, 2);
    return choice + 1;
}

int SettingsMenu::GetStartingChips() const
{
    _consoleUI->Clear();

    const vector<string> options = { "100", "500", "1000", "5000" };
    _consoleUI->DrawTextWithColor(0, 0, "Select starting chips:");
    const int choice = _consoleUI->GetArrowSelection(options, 0, 2);
    return stoi(options[choice]);
}

Difficulty SettingsMenu::GetDifficulty() const
{
    _consoleUI->Clear();

    const vector<string> options = { "Easy", "Normal", "Hard" };
    _consoleUI->DrawTextWithColor(0, 0, "Select difficulty level:");
    const int choice = _consoleUI->GetArrowSelection(options, 0, 2);
    return static_cast<Difficulty>(choice);
}