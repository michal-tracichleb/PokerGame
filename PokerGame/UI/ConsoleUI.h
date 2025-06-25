#pragma once

#include <string>
#include <vector>
#include <Windows.h>

#include "Enumes/TextColor.h"

class ConsoleUI {
public:
    ConsoleUI();
    
    void SetupWindow() const;
    void Clear() const;

    void SetCursorPosition(int x, int y) const;
    void SetTextColor(TextColor color) const;
    void ResetTextColor() const;
    void DrawTextWithColor(int x, int y, const std::string& text, TextColor color = TextColor::Default) const;
    
    int GetArrowSelection(const std::vector<std::string>& options, int x, int y) const;

private:
    HANDLE _hOut;    
};
