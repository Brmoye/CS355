#include <iostream>
#include "FizzBuzz.h"
#include <windows.h>	// to clear console

using namespace std;

/***************************************************************************
 * Function Name: clear_screen
 * Description: Function I found online during CS255 that clears the Windows console
 * 	screen when called because system("cls") is a no-no.
 *  https://stackoverflow.com/questions/5866529/how-do-we-clear-the-console-in-assembly/5866648#5866648
 ***************************************************************************/
void clear_screen(char fill = ' ')
{
    COORD tl = {0,0};
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

int displayMenu()
{
    int choice;

    cout << "Welcome to FizzBuzz!" << endl;
    cout << "Please make a selection:" << endl;
    cout << "1. Set a new limit" << endl;
    cout << "2. Run FizzBuzz" << endl;
    cout << "3. Exit" << endl;

    cin >> choice;

    return choice;
}

int newLimit()
{
    int newLim;

    cout << "Please enter the new limit: ";
    cin >> newLim;
    cout << endl;

    if(newLim < 1)
    {
        cout << "Invalid limit, must be greater than 1." << endl;
        newLimit();
    }

    return newLim;
}

int main()
{
    int choice;
    bool cont = true;
    FizzBuzz game;

    while(cont)
    {
        choice = displayMenu();

        if(choice == 1)
        {
            clear_screen();

            game.setLimit(newLimit());
        }

        else if(choice == 2)
        {
            clear_screen();

            game.run();
            cout << endl;
        }

        else if(choice == 3)
        {
            cont = false;
        }

        else
        {
            cout << endl;
            cout << "Invalid selection, please try again." << endl;
            cout << endl;
        }
    }

    return 0;
}
