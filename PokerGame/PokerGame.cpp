#ifdef _WIN32
#include <windows.h>
#endif

#include <algorithm>
#include <iostream>

#include "Core/Deck.h"

using namespace std;

int main(int argc, char* argv[])
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // console output to UTF-8
#endif

    vector<Card> sorted;
    auto deck = Deck();
    cout << "=== Deck Shuffle ===\n";

    while (deck.IsEmpty() == false)
    {
        sorted.push_back(deck.Deal());
        cout << sorted.back().ToString() << "";
    }
    
    cout << "\n=== Deck Sorted ===\n";
    sort(sorted.begin(), sorted.end(), greater<>());
    for (auto it = sorted.begin(); it != sorted.end(); it++)
    {
        cout << it->ToString() << "";
    }
    
    return 0;
}
