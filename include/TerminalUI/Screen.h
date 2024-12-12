#include <stdio.h>

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

struct Shape;

struct Shape 
{
    struct Square sqr;
    int idx;
    struct Shape* nxt;
};

int drawSquare(struct Square rect, FILE* fptr);

int clearScreen(FILE* fptr);

int moveCursor(int x, int y, FILE* fptr);

int resetCursorPosition(FILE* fptr);

int setColor(struct Color col, FILE* fptr);

int resetColor(FILE* fptr);

struct Color makeColor(int r, int g, int b);

struct Square makeSquare(int x, int y, struct Color col);

struct Shape* makeShape(struct Square sqr);

struct Shape* addSquareToShape(struct Shape* shp, struct Square sqr);

int deleteShape(struct Shape* shp);

int drawBorder(int x1, int y1, int x2, int y2, FILE *fptr);