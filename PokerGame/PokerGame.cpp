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

    auto* ui = new ConsoleUI();
    ui->SetupWindow();
    MainMenu menu(ui);
    
    do
    {
        const MainMenuOption choice = menu.Run();
    
        if (choice == MainMenuOption::Play) {
            SettingsMenu settings(ui);
            GameSettings gs = settings.Run();
            //GameManager game(gs);
            //game.Start();
        }

        if (choice == MainMenuOption::Rank)
        {
            ui->Clear();
            
            cout << "One day... your name will shine here with eternal poker glory.";
            // TODO: For now, it's just a lonely placeholder dreaming of fame.
            
            cin.get();
        }
    } while (true);
}