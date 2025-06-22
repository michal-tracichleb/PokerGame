#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>

#include "Core/Deck.h"

using namespace std;

int main(int argc, char* argv[])
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // console output to UTF-8
#endif

    auto deck = Deck();
    cout << "=== Before shuffle ===\n";
    for (int i = 0; i < DeckSize; i++)
    {
        cout << deck.Deal(i).ToString() << " ";
    }
    
    
    deck.Shuffle();
    cout << "\n=== After shuffle ===\n";
    for (int i = 0; i < DeckSize; i++)
    {
        cout << deck.Deal(i).ToString() << " ";
    }
    
    return 0;
}
