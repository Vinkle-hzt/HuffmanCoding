#include "menu.h"

using namespace std;

/**
 * @brief 展示选择菜单
 * @author 王玉涵
 * 
 */
static void showMenu()
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