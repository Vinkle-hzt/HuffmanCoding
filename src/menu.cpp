#include "menu.h"

using namespace std;

void showMenu()
{
    cout << "hello world" << endl;
}

void startMenu()
{
    bool exitFlag = false;
    while (!exitFlag)
    {
        showMenu();
        exitFlag =true;
    }
}