#pragma once

#include <string>
#include <vector>

class ConsoleUI {
public:
    static void SetupWindow();
    static void Clear();
    static void DrawTextHighlight(int x, int y, const std::string& text, bool highlight);
    static int GetArrowSelection(const std::vector<std::string>& options, int x, int y);
};
