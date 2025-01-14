#include <stdio.h>
#include "game.h"

void printintro() {
    printf("...Dialoge This is connect 4:\n");
}
void mainmenu() {
    char mainmenuoption;
    printf("What do you want to do?\n");
    printf("Type [1] to start a local game!\n");
    printf("Type [2] to create a new online game!\n");
    printf("Type [3] to continue an online game!\n");
    printf("Type [q] to quit the game :(\n");
    scanf(" %c", &mainmenuoption);
    switch (mainmenuoption) {
        //Enter gameloop
        case '1':
            gamesetuplocal();
        //Enter gameloop
        case '2':
            gamesetuponline();
        //Option to quit the game
        case 'q':
            printf("Thank you for playing Connect4!\n");
            return;
        //Detect invalid inputs(try again)
        default:
            printf("This is not a valid input! Please try again!\n");
            mainmenu();
    }
}
int main(void) {
    printintro();
    mainmenu();
    return 0;
}
