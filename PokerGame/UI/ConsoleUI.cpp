#include <windows.h>
#include <iostream>
#include <conio.h>
#include <vector>

#include "ConsoleUI.h"
#include "Enumes/Key.h"
#include "Enumes/TextColor.h"

using namespace std;

ConsoleUI::ConsoleUI()
{
    _hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetupWindow();
}

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


void ConsoleUI::SetCursorPosition(const int x, const int y) const
{
    const COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(_hOut, coord);
}

void ConsoleUI::SetTextColor(const TextColor color) const
{
    SetConsoleTextAttribute(_hOut, static_cast<WORD>(color));
}

void ConsoleUI::ResetTextColor() const
{
    SetTextColor(TextColor::Default);
}

void ConsoleUI::DrawTextWithColor(const int x, const int y, const string& text, const TextColor color) const
{
    SetCursorPosition(x, y);
    SetTextColor(color);
    cout << text;
    ResetTextColor();
}

int ConsoleUI::GetArrowSelection(const vector<string>& options, const int x, const int y) const
{
    int selected = 0;

    while (true)
    {
        for (int i = 0; i < static_cast<int>(options.size()); ++i)
        {
            TextColor color = (i == selected) ? TextColor::Yellow : TextColor::Default;
            DrawTextWithColor(x, y + i, options[i], color);
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
