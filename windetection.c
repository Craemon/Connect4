#include <stdbool.h>

//checks for horizontal wins
bool winhorizontal (int row, int col, char board[row][col], int requiredtowin, int tokenrow, int tokencol, char token) {
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

//checks for vertical wins
bool winvertical(int row, int col, char board[row][col], int requiredtowin, int tokenrow, int tokencol, char token) {
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

//checks for diagonal wins
bool windiagonal1(int row, int col, char board[row][col], int requiredtowin, int tokenrow, int tokencol, char token) {
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

//checks for diagonal wins(other diagonal)
bool windiagonal2(int row, int col, char board[row][col], int requiredtowin, int tokenrow, int tokencol, char token) {
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

//checks if board completely full => draw
bool drawdetection(int row, int col, char board[row][col]) {
    for (int i = 0; i < col; i++) {
        if (board[0][i] == ' ') {
            return false;
        }
    }
    return true;
}