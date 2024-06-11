#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// Function declarations in this file:
#include "functions.h"

// The main attraction!
int main()
{
    // Random seed based on time. 
    srand(time(NULL));

    // Starting the SVG file and setting up the window width, height, and background color. 
    char color[8];
    getHexCode(166, 220, 247, color);
    beginHtmlSVG(1920, 1080, color);

    // Initializing variables.
    int x;
    int y;
    int red;
    int green;
    int blue;
    int width;
    int height;
    int depth;
    float shadowAmount;

    // Drawing all the cubes!
    for(int i = 0; i < 100; i++)
    {
        x = (rand() % 1801) + 100;
        y = (rand() % 901) + 100;
        red = rand() % 256;
        green = rand() % 256;
        blue = rand() % 256;
        width = (rand() % 126) + 25;
        height = (rand() % 126) + 25;
        depth = (rand() % 126) + 25;
        shadowAmount = (float) rand() / (float) RAND_MAX;
        cube(x, y, width, height, depth, red, green, blue, shadowAmount);
    }

    // Drawing all the snowflakes!
    for(int i = 0; i < 150; i++) 
    {
        x = (rand() % 1801) + 100;
        y = (rand() % 901) + 100;
        red = rand() % 256;
        green = rand() % 256;
        blue = rand() % 256;
        snowflake(x, y, red, green, blue, i);
    }
    
    // Ending the SVG file.
    endHtmlSVG();

    return 0;
}