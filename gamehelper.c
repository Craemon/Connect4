#include <stdbool.h>
#include <stdio.h>

// Function to initialize the playing field with "free spots"
void initboard(int row, int col, char board[row][col]){
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            board[i][j] = ' ';
        }
    }
}
// Function to print the board
void printboard(int row, int col, char board[row][col]) {
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
//attempts to place token, returns if placement was successful
int placetoken(int row, int col, char board[row][col], int chosencol, char token) {
    for(int i = row-1; i >=0; i--) {
        if (board[i][chosencol] == ' ') {
            board[i][chosencol] = token;
            return i;
        }
    }
    return -1;
}
//stops invalid inputs in column scan
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