#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>

#include "UI/ConsoleUI.h"
#include "UI/MainMenu.h"
#include "UI/Enumes/MainMenuOption.h"

using namespace std;

int main(int argc, char* argv[])
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // console output to UTF-8
#endif
    
    do
    {
        ConsoleUI consoleUI;
        consoleUI.SetupWindow();

        MainMenu menu(&consoleUI);
        const MainMenuOption choice = menu.Run();
    
        if (choice == MainMenuOption::Play) {
            cout << "\n\nPlay";
            //     SettingsMenu settings;
            //     GameSettings gs = settings.Run();
            //
            //     GameManager game(gs);
            //     game.Start();
        }

        if (choice == MainMenuOption::Rank)
        {
            cout << "\n\nRank";
        }
    
        cin.get();
    } while (true);
}