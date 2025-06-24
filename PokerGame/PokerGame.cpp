#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>

#include "UI/ConsoleUI.h"
#include "UI/MainMenu.h"
#include "UI/SettingsMenu.h"
#include "UI/Enumes/MainMenuOption.h"

using namespace std;

int main(int argc, char* argv[])
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // console output to UTF-8
#endif

    ConsoleUI::SetupWindow();
    ConsoleUI ui;
    MainMenu menu(&ui);
    
    do
    {
        const MainMenuOption choice = menu.Run();
    
        if (choice == MainMenuOption::Play) {
            SettingsMenu settings(&ui);
            GameSettings gs = settings.Run();

            cout << gs.numberOfOpponents << endl;
            cout << gs.startingChips << endl;
            cout << static_cast<int>(gs.difficulty) << endl;
            
            //     GameManager game(gs);
            //     game.Start();

            cin.get();
        }

        if (choice == MainMenuOption::Rank)
        {
            cout << "\n\nRank";
            cin.get();
        }
        
    } while (true);
}