#ifndef WINDETECTION_H
#define WINDETECTION_H

bool winhorizontal (int row, int col, char board[row][col], int requiredtowin, int tokenrow, int tokencol, char token);
bool winvertical(int row, int col, char board[row][col], int requiredtowin, int tokenrow, int tokencol, char token);
bool windiagonal1(int row, int col, char board[row][col], int requiredtowin, int tokenrow, int tokencol, char token);
bool windiagonal2(int row, int col, char board[row][col], int requiredtowin, int tokenrow, int tokencol, char token);
bool drawdetection(int row, int col, char board[row][col]);

#endif //WINDETECTION_H
