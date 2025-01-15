#include <stdio.h>
#include <string.h>

void gengamecode(int row, int col, char board[row][col], int currentplayer) {
    //first converts 2d-array to a 1d-array (because I'm too stupid to do it without extra steps)
    char onedarray[42];
    int onedarrayindex = 0;
    for(int j = 0; j < sizeof onedarray; j++) {
        onedarray[j] = ' ';
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            char convertspace = board[i][j];
            if (convertspace == ' ') {
                convertspace = '#';
            }
            onedarray[onedarrayindex] = convertspace;
            onedarrayindex++;
        }
    }

    //init gamecode array
    char currentchar='€'; int consecutivechars = 0; //initialize with impossible character "€"
    char gamecode[86]; int gamecodeindex = 0;
    for(int i = 0; i < strlen(onedarray); i++) {
        gamecode[i] = ' ';
    }
    //first number in gamecode indicates whose turn it currently is
    char currentplayerchar[1];
    sprintf(currentplayerchar, "%d", currentplayer);
    gamecode[gamecodeindex] = currentplayerchar[0];
    gamecodeindex++;
    //compresses the created 1d-array to the final gamecode
    for (int i = 0; i <= strlen(onedarray); i++) {
        if (onedarray[i] == currentchar) {
            consecutivechars++;
        } else {
            if (consecutivechars > 0) {
                gamecode[gamecodeindex] = currentchar;
                gamecodeindex++;
                char tempchar[10];
                sprintf(tempchar, "%d", consecutivechars);
                int stoppoint = strlen(tempchar);
                for (int j = 0; j < stoppoint; j++) {
                    gamecode[gamecodeindex] = tempchar[j];
                    gamecodeindex++;
                }
            }
            currentchar = onedarray[i];
            consecutivechars = 1;
        }
    }
    // adding last char to gamecode
    if (consecutivechars > 0) {
        gamecode[gamecodeindex] = currentchar;
        gamecodeindex++;
        char tempchar[10];
        sprintf(tempchar, "%d", consecutivechars);
        int stoppoint = strlen(tempchar);
        for (int j = 0; j < stoppoint; j++) {
            gamecode[gamecodeindex] = tempchar[j];
            gamecodeindex++;
        }
    }
    //output final gamecode
    printf("Send this gamecode to another person!\n");
    printf("They can enter it by choosing option 3 in the main menu:\n");
    printf("%s", gamecode);
    printf("$\n"); //trailing character to signal end of code on import
}