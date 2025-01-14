#include <stdio.h>
#include <stdbool.h>
#include "gamehelper.h"
#include "windetection.h"
#include "onlinegamehelper.h"

void gamelooplocal(int row, int col, char board[row][col], int requiredtowin) {
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
void gamerunonline(int row, int col, char board[row][col], int requiredtowin, int currentplayer) {
    char token;
    int chosencol;
    if (currentplayer == 1) {
        token = 'X';
    } else {
        token = 'O';
    }
    printboard(row, col, board);
    int tokenrow = -1;
    while (tokenrow == -1) {
        printf("It's Player %d's turn:\n",currentplayer);
        printf("Please choose a column (1-%d) to place your token in:\n",col);
        chosencol = input_valid_game(col);
        tokenrow = placetoken(row, col, board, chosencol - 1, token);
        if (tokenrow == -1) {
            printf("Column full error\n");
        }
    }
    int tokencol = chosencol-1;
    if (winhorizontal(row,col,board,requiredtowin,tokenrow,tokencol,token)||winvertical(row,col,board,requiredtowin,tokenrow,tokencol,token)||windiagonal1(row,col,board,requiredtowin,tokenrow,tokencol,token)||windiagonal2(row,col,board,requiredtowin,tokenrow,tokencol,token)) {
        printf("You win\n");
        printboard(row, col, board);
    }else if (drawdetection(row, col, board)) {
        printf("Board full.\n");
        printboard(row, col, board);
    } else {
        if (currentplayer == 1) {
            currentplayer = 2;
        } else {
            currentplayer = 1;
        }
        printboard(row, col, board);
        gengamecode(row, col, board, currentplayer);
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
void gamesetuplocal() {
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
    gamelooplocal(row, col, board, requiredtowin);
}
void gamesetuponline() {
    printf("You've started a online game!\n");
    int row = 6; int col = 7; int requiredtowin = 4;
    char board[row][col];
    int currentplayer = 1;
    initboard(row, col, board);
    gamerunonline(row, col, board, requiredtowin, currentplayer);
}
void gameimport() {
    printf("You're continuing an online game via gamecode!\n");
    printf("Please enter your gamecode:");
    char gamecode[64];
    scanf("%s", gamecode);
    printf("Your gamecode is:\n");
    printf("%s", gamecode);
}