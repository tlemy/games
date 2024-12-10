#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Color 
{
    int r;
    int g;
    int b;
};

struct Square
{
    int x;
    int y;
    struct Color col;
};

int drawSquare(struct Square rect, FILE* fptr);

int clearScreen(FILE* fptr);

int moveCursor(int x, int y, FILE* fptr);

int resetCursorPosition(FILE* fptr);

int setColor(struct Color col, FILE* fptr);

int resetColor(FILE* fptr);

struct Color makeColor(int r, int g, int b);

struct Square makeSquare(int x, int y, struct Color col);