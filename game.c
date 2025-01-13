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
        printf("====");
    }
    printf("=\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    for(int j = 0; j < col; j++) {
        printf("====");
    }
    printf("=\n");
}

int placetoken(char board[row][col], int chosencol, char token) {
    //attempts to place token, returns if placement was successful
    for(int i = row-1; i >=0; i--) {
        if (board[i][chosencol] == ' ') {
            board[i][chosencol] = token;
            return i;
        }
    }
    return -1;
}
bool winhorizontal (char board[row][col], int tokenrow, int tokencol, char token) {
    int consecutivetokens = 0;
    int startpos = tokencol - (requiredtowin-1);
    int endpos = tokencol + (requiredtowin-1);
    if (startpos < 0) {
        startpos =0;
    }
    if (endpos >= col) {
        endpos = col-1;
    }
    for(int i = startpos; i <= endpos; i++) {
        if(board[tokenrow][i] == token) {
            consecutivetokens++;
        } else {
            consecutivetokens = 0;
        }
        if(consecutivetokens >= requiredtowin) {
            return true;
        }
    }
    return false;
}
bool winvertical(char board[row][col], int tokenrow, int tokencol, char token) {
    int consecutivetokens = 0;
    int startpos = tokenrow - (requiredtowin-1);
    int endpos = tokenrow + (requiredtowin-1);
    if (startpos < 0) {
        startpos =0;
    }
    if (endpos >= row) {
        endpos = row-1;
    }
    for(int i = startpos; i <= endpos; i++) {
        if(board[i][tokencol] == token) {
            consecutivetokens++;
        } else {
            consecutivetokens = 0;
        }
        if(consecutivetokens >= requiredtowin) {
            return true;
        }
    }
    return false;
}
bool windiagonal1(char board[row][col], int tokenrow, int tokencol, char token) {
    int consecutivetokens = 0;
    int startposrow = tokenrow - (requiredtowin-1);
    int endposrow = tokenrow + (requiredtowin-1);
    int startposcol = tokencol - (requiredtowin-1);
    for(int i = startposrow, j=startposcol; i <= endposrow; i++,j++) {
        if (i < 0 || i >= row || j < 0 || j >= col) {
            continue;
        }
        if(board[i][j] == token) {
            consecutivetokens++;
        } else {
            consecutivetokens = 0;
        }
        if(consecutivetokens >= requiredtowin) {
            return true;
        }
    }
    return false;
}
bool windiagonal2(char board[row][col], int tokenrow, int tokencol, char token) {
    int consecutivetokens = 0;
    int startposrow = tokenrow + (requiredtowin-1);
    int endposrow = tokenrow - (requiredtowin-1);
    int startposcol = tokencol - (requiredtowin-1);
    for(int i = startposrow, j=startposcol; i >= endposrow; i--,j++) {
        if (i < 0 || i >= row || j < 0 || j >= col) {
            continue;
        }
        if(board[i][j] == token) {
            consecutivetokens++;
        } else {
            consecutivetokens = 0;
        }
        if(consecutivetokens >= requiredtowin) {
            return true;
        }
    }
    return false;
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
        int tokenrow = -1;
        tokenrow = placetoken(board, chosencol-1, token);
        if (tokenrow == -1) {
            printf("Column full error\n");
            continue;
        }
        int tokencol = chosencol-1;
        if (winhorizontal(board,tokenrow,tokencol,token)||winvertical(board,tokenrow,tokencol,token)||windiagonal1(board,tokenrow,tokencol,token)||windiagonal2(board,tokenrow,tokencol,token)) {
            printf("You win\n");
            printboard(board);
            gameWon = true;
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
    gameloop(board);
}
