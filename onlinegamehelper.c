#include <stdio.h>
#include <string.h>

void gengamecode(int row, int col, char board[row][col], int currentplayer) {
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

    // Null-terminate the string after filling the array
    onedarray[onedarrayindex] = '\0';

    char currentchar='€'; int consecutivechars = 0; //initialize with impossible character "€"
    char gamecode[43]; int gamecodeindex = 0;
    for(int i = 0; i < strlen(onedarray); i++) {
        gamecode[i] = ' ';
    }
    char currentplayerchar[1];
    sprintf(currentplayerchar, "%d", currentplayer);
    gamecode[gamecodeindex] = currentplayerchar[0];
    gamecodeindex++;
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
        gamecode[gamecodeindex++] = currentchar;
        char tempchar[10];
        sprintf(tempchar, "%d", consecutivechars);
        int stoppoint = strlen(tempchar);
        for (int j = 0; j < stoppoint; j++) {
            gamecode[gamecodeindex] = tempchar[j];
            gamecodeindex++;
        }
    }

    // Null-terminate the encoded string
    gamecode[gamecodeindex] = '\0';
    printf("Send this gamecode to another person!\n");
    printf("They can enter it by choosing option 3 in the main menu:\n");
    printf("%s\n", gamecode);
}

void decodegamecode() {

}