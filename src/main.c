#include "rogue.h"

int main ()
{
    Player * user;
    int ch;

    screenSetUp();

    mapSetUp();

    user = playerSetUp();

    playerSetUp();

    /*main game loop*/
    while((ch = getch()) != 'q')
    {
        handleInput(ch, user);

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


Room ** mapSetUp()
{

    Room ** rooms;
    rooms = malloc(sizeof(Room)*6);
    // mvprintw(13, 13, "--------");
    // mvprintw(14, 13, "|......|");
    // mvprintw(15, 13, "|......|");
    // mvprintw(16, 13, "|......|");
    // mvprintw(17, 13, "|......|");
    // mvprintw(18, 13, "--------");

    rooms[0] = createRoom(13, 13, 6, 8);
    drawRoom(rooms[0]);

    // mvprintw(2, 40, "--------");
    // mvprintw(3, 40, "|......|");
    // mvprintw(4, 40, "|......|");
    // mvprintw(5, 40, "|......|");
    // mvprintw(6, 40, "|......|");
    // mvprintw(7, 40, "--------");

    rooms[1] = createRoom(2, 40, 6, 8);
    drawRoom(rooms[1]);

    // mvprintw(10, 40, "------------");
    // mvprintw(11, 40, "|..........|");
    // mvprintw(12, 40, "|..........|");
    // mvprintw(13, 40, "|..........|");
    // mvprintw(14, 40, "|..........|");
    // mvprintw(15, 40, "------------");

    rooms[2] = createRoom(10, 40, 6, 12);
    drawRoom(rooms[2]);

    connectDoors(rooms[0]->doors[3], rooms[2]->doors[1]);
    connectDoors(rooms[1]->doors[2], rooms[0]->doors[0]);

    return rooms;

}

