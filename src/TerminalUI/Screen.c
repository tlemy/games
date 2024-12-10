#include "../../include/TerminalUI/Screen.h"

#define SQUARE "\u2593\u2593\0" // 2 ANSI full block characters

// ANSI escape sequences
#define CLEAR_SCREEN "\033[2J\033[3J\033[?25l" // clear screen, erase scroll back buffer and hides the cursor
#define MOVE_CURSOR "\033[%d;%dH" // (y, x)
#define RESET_CURSOR_POSITION "\033[2J\033[H" // move cursor to top left
#define SET_COLOR "\033[38;2;%d;%d;%dm" // (r, g, b)
#define RESET_COLOR "\033[0m"

// private 

int writeToFptr(char *str, FILE* fptr) 
{
    if (fptr == NULL) 
    {
        return -1;
    }

    int lenStr = strlen(str);
    size_t writeSize = fwrite(str, sizeof(char), lenStr, fptr);
    bool wroteAll = sizeof(char) * lenStr == writeSize;
    int flushed = fflush(fptr) == 0;

    if (wroteAll && flushed) 
    {
        return 0;
    }
    return 1;
}

// public

int drawSquare(struct Square rect, FILE* fptr) 
{
    char input[] = SQUARE;
    return writeToFptr(input, fptr);
}

int clearScreen(FILE* fptr) 
{
    char input[] = CLEAR_SCREEN;
    return writeToFptr(input, fptr);
}

int moveCursor(int x, int y, FILE* fptr) 
{
    char input[32];
    int len = sprintf(input, MOVE_CURSOR, y, x);

    if (len != strlen(input)) 
    {
        return -1;
    }

    return writeToFptr(input, fptr);
}

int resetCursorPosition(FILE* fptr) 
{
    char input[] = RESET_COLOR;
    return writeToFptr(input, fptr);
}

int setColor(struct Color col, FILE* fptr) 
{
    char input[32];
    int len = sprintf(input, SET_COLOR, col.r, col.g, col.b);

    if (len != strlen(input)) 
    {
        return -1;
    }

    return writeToFptr(input, fptr);
}

int resetColor(FILE* fptr) 
{
    char input[] = RESET_COLOR;
    return writeToFptr(input, fptr);
}

struct Color makeColor(int r, int g, int b) 
{
    struct Color col;
    col.r = r;
    col.g = g;
    col.b = b;

    return col;
}

struct Square makeSquare(int x, int y, struct Color col) 
{
    struct Square square;
    square.x = x;
    square.y = y;
    square.col = col;

    return square;
}

struct Shape makeShape(int w, int h) 
{
    struct Shape shape;
    shape.w = w;
    shape.h = h;
    shape.mtrx = (struct Square**) malloc(sizeof(struct Square) * w * h);

    return shape;
}

int addRowToShape(struct Shape* shp) 
{

}

int addSquareToRowShape(struct Shape* shp, struct Square sqr, int r) 
{
    
}

int deleteShape(struct Shape shp) 
{
    if (shp.h == 0) 
    {
        return 1;
    }

    if (shp.mtrx == NULL) 
    {
        return -1;
    }
    
    for (int r = 0; r < shp.h; r++) 
    {
        if (shp.mtrx[r] == NULL) 
        {
            return -1;
        }
        free(shp.mtrx[r]);
    }

    return 0;
}