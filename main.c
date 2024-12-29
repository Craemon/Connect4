#include <stdio.h>

void printmainmenu() {
    printf("...Dialoge This is the mainmenu:\n");
    printf("What do you want to do?\n");
    printf("Type [1] to\n");
    printf("Type [2] to\n");
    printf("Type [q] to quit the game :(\n");
}
int main(void) {
    char mainmenuoption;
    printmainmenu();
    scanf("%c", &mainmenuoption);
    switch (mainmenuoption) {
        //Option to quit the game
        case '1':

        case 'q':
            printf("Thank you for playing Connect4!\n");
        return 0;
        //Detect invalid inputs
        default:
            printf("This is not a valid input! Please try again!\n");
    }
    return 0;
}