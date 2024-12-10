#include "../../include/TerminalUI/Screen.h"
#include <unistd.h>

int main()
{
    const int numColors = 4;
    const struct Color red = makeColor(255, 0, 0);
    const struct Color green = makeColor(0, 255, 0);
    const struct Color blue = makeColor(0, 0, 255);
    const struct Color yellow = makeColor(255, 255, 0);
    const struct Color colors[numColors] = {red, green, blue, yellow};
    
    int colorIdx = 0;
    struct Square sqr = makeSquare(0, 0, colors[colorIdx]);
    
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

        printf("(x: %d, y: %d) (r: %d, g: %d, b: %d)\n", sqr.x, sqr.y, sqr.col.r, sqr.col.g, sqr.col.b);

        if (resetCursorPosition(stdout) != 0) 
        {
            printf("Error: resetCursorPosition\n");
            break;
        }

        ++colorIdx;

        if (colorIdx >= numColors) 
        {
            colorIdx = 0;
        }

        sqr.col = colors[colorIdx];  
        sleep(2);
    }
}