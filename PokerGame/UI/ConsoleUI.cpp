#include <windows.h>
#include <iostream>
#include <conio.h>
#include <vector>

#include "ConsoleUI.h"
#include "Enumes/Key.h"

using namespace std;

void ConsoleUI::SetupWindow()
{
    // TODO: resize window
    
    // constexpr int width = 120;
    // constexpr int height = 30;
    
    // HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // COORD bufferSize = { static_cast<SHORT>(width), static_cast<SHORT>(height) };
    // if (!SetConsoleScreenBufferSize(hOut, bufferSize))
    //     cerr << "Failed to set buffer size\n";
    
    // SMALL_RECT windowSize = { 0, 0, static_cast<SHORT>(width - 1), static_cast<SHORT>(height - 1) };
    // if (!SetConsoleWindowInfo(hOut, TRUE, &windowSize))
    //     cerr << "Failed to set window size\n";

    const string title = "Texas Hold'em";
    Clear();
    SetConsoleTitleA(title.c_str());
}

void ConsoleUI::Clear()
{
    system("cls");
}

void ConsoleUI::DrawTextHighlight(const int x, const int y, const string& text, const bool highlight)
{
    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, coord);

    if (highlight)
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
    else
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    cout << text;

    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int ConsoleUI::GetArrowSelection(const vector<string>& options, const int x, const int y)
{
    int selected = 0;

    while (true)
    {
        for (int i = 0; i < static_cast<int>(options.size()); ++i)
        {
            DrawTextHighlight(x, y + i, options[i], i == selected);
        }

        int key = _getch();

        if (key == static_cast<int>(Key::Arrows))
        {
            key = _getch();
            switch (key)
            {
            case static_cast<int>(Key::ArrowUp):
                selected = (selected - 1 + options.size()) % options.size();
                break;
            case static_cast<int>(Key::ArrowDown):
                selected = (selected + 1) % options.size();
                break;
            default:
                break;
            }
        }
        else if (key == static_cast<int>(Key::Enter))
        {
            return selected;
        }
    }
}
