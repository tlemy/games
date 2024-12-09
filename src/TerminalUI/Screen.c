#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SQUARE "\u2593\u2593\0"

int drawSquare(int x, int y, int r, int g, int b, FILE* fptr) 
{
    int lenStr = strlen(SQUARE);
    size_t writeSize = fwrite(&SQUARE, sizeof(char), lenStr, fptr);
    bool wroteAll = sizeof(char) * lenStr == writeSize;

    return wroteAll - 1;
}

int clearScreen() 
{
    return 0;
}