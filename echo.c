#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define UPPER_CONV 32

/**
    Converts given string to uppercase
*/
char* toUpper(char* str) {
    char* upperStr = malloc((strlen(str) + 1) * sizeof(char));
    for (int i = 0; i < strlen(str); i++) {
        if ((str[i] >= 97) && (str[i] <= 122))
            upperStr[i] = (char) (str[i] - UPPER_CONV);
        else
            upperStr[i] = str[i];
    }
    upperStr[strlen(str)] = '\0';

    return upperStr;
}

int main(int argc, char* argv[]) {
    /* Check args are correct */
    if (argc < 2) {
        fprintf(stderr, "Correct usage is 'echoMe args'\n");
        return 1;
    }

    /* Process flags */
    bool upperFlag = false;
    int startPos = 1;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (strlen(argv[i]) != 2) { return 1; }

            char flag = argv[i][1];
            switch (flag) {
                case 'u':
                    upperFlag = true;
                    startPos++;
                    break;
                
                default:
                    fprintf(stderr, "Arg %c not recognized\n", flag);
                    return 1;
                }
        }
        else {
            break;
        }
    }

    for (int i = startPos; i < argc; i++) {
        if (upperFlag) {
            char* upperStr = toUpper(argv[i]);
            printf("%s", upperStr);
            free(upperStr);
        }
        else {
            printf("%s", argv[i]);
        }
        if (i < argc - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}