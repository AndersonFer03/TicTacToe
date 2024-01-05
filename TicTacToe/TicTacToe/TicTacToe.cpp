
#include "menu.h"
int main()
{
    Menu* menu = new Menu();
    menu->initializeWindow();
    menu->loadBackground("images/game.png");
    Text play;
    //menu->render();
    menu->drawMenu();
    menu->showWindow();
    while (menu->getWindowState()) {
        menu->handleEvents();
    }


    return 0;
}