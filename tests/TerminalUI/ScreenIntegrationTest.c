#include "../../include/TerminalUI/Screen.h"
#include <stdbool.h>
#include <unistd.h>

int main()
{
    const offset = 2;
    const initX = 0 + offset;
    const initY = 0 + offset;
    const maxX = 22 + offset;
    const maxY = 11 + offset;
    const int numColors = 4;
    const struct Color red = makeColor(255, 0, 0);
    const struct Color green = makeColor(0, 255, 0);
    const struct Color blue = makeColor(0, 0, 255);
    const struct Color yellow = makeColor(255, 255, 0);
    const struct Color colors[numColors] = {red, green, blue, yellow};
    
    int colorIdx = 0;
    struct Square sqr = makeSquare(initX, initY, colors[colorIdx]);
    
    while (true) 
    {
        if (clearScreen(stdout) != 0) 
        {
            printf("Error: clearScreen");
            break;
        }

        if (moveCursor(sqr.x, sqr.y, stdout) != 0) 
        {
            printf("Error: moveCursor\n");
            break;
        }

        if (setColor(sqr.col, stdout) != 0) 
        {
            printf("Error: setColor\n");
            break;
        }
        
        if (drawSquare(sqr, stdout) != 0) 
        {
            printf("Error: drawSquare\n");
            break;
        }

        if (resetColor(stdout) != 0) 
        {
            printf("Error: resetColor\n");
            break;
        }

        // top border
        if (drawBorder(initX - 1, initY - 1, maxX + 1, initY - 1, stdout) == -1) 
        {
            printf("Error: drawBorder (top)\n");
            break;
        }

        // bottom border
        if (drawBorder(initX - 1, maxY, maxX + 1, maxY, stdout) == -1) 
        {
            printf("Error: drawBorder (bottom)\n");
            break;
        }

        // left border
        if (drawBorder(initX - 1, initY - 1, initX - 1, maxY, stdout) == -1) 
        {
            printf("Error: drawBorder (left)\n");
            break;
        }

        // right border
        if (drawBorder(maxX, initY - 1, maxX, maxY, stdout) == -1)
        {
            printf("Error: drawBorder (right)\n");
            break;
        }

        if (moveCursor(0, maxY + 2, stdout) != -1) 
        {
            printf("(x: %d, y: %d) (r: %d, g: %d, b: %d)\n", sqr.x, sqr.y, sqr.col.r, sqr.col.g, sqr.col.b);
        }

        if (resetCursorPosition(stdout) != 0) 
        {
            printf("Error: resetCursorPosition\n");
            break;
        }

        ++colorIdx;
        sqr.x += 2;
        ++sqr.y;

        if (colorIdx >= numColors) 
        {
            colorIdx = 0;
        }

        if (sqr.x >= maxX) 
        {
            sqr.x = initX;
        }

        if (sqr.y >= maxY) 
        {
            sqr.y = initY;
        }

        sqr.col = colors[colorIdx];  
        sleep(1);
    }
}