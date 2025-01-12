#include <stdio.h>
#include <stdbool.h>
#include "game.h"


// "i" and "j" are index variables

// Function to initialize the playing field with "free spots"
void initboard(char board[row][col]){
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            board[i][j] = ' ';
        }
    }
}
// Function to print the board
void printboard(char board[row][col]) {
    for(int j = 0; j < col; j++) {
        if (j < 9) {
            printf("  %d ", j+1);
        }
        else {
            printf(" %d ", j+1);
        }
    }
    printf("\n");
    for(int j = 0; j < col; j++) {
        printf("====", j + 1);
    }
    printf("=\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    for(int j = 0; j < col; j++) {
        printf("====", j + 1);
    }
    printf("=\n");
}

bool placetoken(char board[row][col], int chosencol, char token) {
    //attempts to place token, returns if placement was successful
    for(int i = row-1; i >=0; i--) {
        if (board[i][chosencol] == ' ') {
            board[i][chosencol] = token;
            return true;
        }
    }
    return false;
}
char windetection() {
    //add win detection
}
bool drawdetection(char board[row][col]) {
    for (int i = 0; i < col; i++) {
        if (board[0][i] == ' ') {
            return false;
        }
    }
    return true;
}
void gameloop(char board[row][col]) {
    int currentplayer = 1; //determines whose turn it is
    char token;
    int chosencol;
    bool gameWon = false; //condition to break out of the game loop once game is over
    while(!gameWon) {
        if (currentplayer == 1) {
            token = 'X';
        } else {
            token = 'O';
        }
        printboard(board);
        printf("It's Player %d's turn:\n",currentplayer);
        printf("Please choose a column (1-%d) to place your token in:\n",col);
        scanf("%d", &chosencol);
        if (chosencol < 1 || chosencol > col) {
            printf("This is not a valid input, please try again.\n");
            continue;
        }
        if (!placetoken(board, chosencol-1, token)) {
            printf("Column full error\n");
            continue;
        }
        if (drawdetection(board)) {
            printf("Board full.\n");
            printboard(board);
            gameWon = true;
        }
        if (currentplayer == 1) {
            currentplayer = 2;
        } else {
            currentplayer = 1;
        }
    }
}
void gamesetup() {
    char board[row][col];
    initboard(board);
    printboard(board);
    gameloop(board);
}
