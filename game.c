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
void gameloop() {
    //add gameloop
    //maby use boolean with while loop?
}
void gamesetup() {
    char board[row][col];
    initboard(board);
    printboard(board);
    gameloop();
}
char windetection() {
    //add wind detection
}
