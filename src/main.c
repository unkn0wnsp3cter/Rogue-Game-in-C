#include "rogue.h"

int main ()
{
    Player * user;
    int ch;
    Position * newPosition;
    char ** level;

    screenSetUp();

    mapSetUp();

    level = saveLevelPositions();

    user = playerSetUp();

    playerSetUp();

    /*main game loop*/
    while((ch = getch()) != 'q')
    {
        newPosition = handleInput(ch, user);
        checkPosition(newPosition, user, level);
    }

    getch();

    endwin();

    return 0;
}


int screenSetUp()
{
    initscr();
    printw("Hello World!");
    noecho();
    refresh();

    srand(time(NULL));

    return 1;

}

