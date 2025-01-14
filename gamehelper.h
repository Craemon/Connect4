

#ifndef GAMEHELPER_H
#define GAMEHELPER_H

void initboard(int row, int col, char board[row][col]);
void printboard(int row, int col, char board[row][col]);
int placetoken(int row, int col, char board[row][col], int chosencol, char token);

#endif //GAMEHELPER_H
