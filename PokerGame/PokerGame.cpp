#include <iostream>
#include "Core/Card.h"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main(int argc, char* argv[])
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // console output to UTF-8
#endif
    
     for (int i = 0; i < static_cast<int>(Color::Size); i++)
     {
         for (int j = 0; j < static_cast<int>(Value::Size); j++)
         {
             auto temporaryCard = Card(static_cast<Color>(i), static_cast<Value>(j));
     
             cout << temporaryCard.ToString() << "\n";
         }
     }
    
    return 0;
}
