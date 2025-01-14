#include <stdio.h>
#include <stdbool.h>
#include "gamehelper.h"
#include "windetection.h"

int input_valid_game(int col) {
    int input;
    while (true) {
        printf("Please enter a number: ");
        if (scanf("%d", &input) == 1) {
            if (input < 1 || input > col) {
                printf("This is not a valid input, please try again.\n");
            } else {
                return input;
            }
        } else {
            printf("This is not a valid input, please try again.\n");
            while (getchar() != '\n');
        }
    }
}
void gameloop(int row, int col, char board[row][col], int requiredtowin) {
    int currentplayer = 1; //determines whose turn it is
    char token;
    bool gameWon = false; //condition to break out of the game loop once game is over
    while(!gameWon) {
        if (currentplayer == 1) {
            token = 'X';
        } else {
            token = 'O';
        }
        printboard(row, col, board);
        printf("It's Player %d's turn:\n",currentplayer);
        printf("Please choose a column (1-%d) to place your token in:\n",col);
        int chosencol = input_valid_game(col);
        int tokenrow = placetoken(row, col, board, chosencol - 1, token);
        if (tokenrow == -1) {
            printf("Column full error\n");
            continue;
        }
        int tokencol = chosencol-1;
        if (winhorizontal(row,col,board,requiredtowin,tokenrow,tokencol,token)||winvertical(row,col,board,requiredtowin,tokenrow,tokencol,token)||windiagonal1(row,col,board,requiredtowin,tokenrow,tokencol,token)||windiagonal2(row,col,board,requiredtowin,tokenrow,tokencol,token)) {
            printf("You win\n");
            printboard(row, col, board);
            gameWon = true;
        }
        if (drawdetection(row, col, board)) {
            printf("Board full.\n");
            printboard(row, col, board);
            gameWon = true;
        }
        if (currentplayer == 1) {
            currentplayer = 2;
        } else {
            currentplayer = 1;
        }
    }
}
int input_valid_int() {
    int input;
    while (true) {
        if (scanf("%d", &input) == 1) {
            if (input < 1) {
                printf("This is not a valid input, please try again.\n");
            } else {
                return input;
            }
        } else {
            printf("This is not a valid input, please try again.\n");
            while (getchar() != '\n');
        }
    }
}
void gamesetup() {
    printf("You've started a local game!\n");
    int row = 6; int col = 7; int requiredtowin = 4; char entergamesettings;
    printf("Do you want to edit the game settings (y/n):");
    scanf(" %c", &entergamesettings);
    if (entergamesettings == 'y') {
        printf("Enter the number of rows(default:6):");
        row = input_valid_int();
        printf("Enter the number of columns(default:7):");
        col = input_valid_int();
        printf("Enter the number of required tokens in a row(default:4):");
        requiredtowin = input_valid_int();
    }
    char board[row][col];
    initboard(row, col, board);
    gameloop(row, col, board, requiredtowin);
}
