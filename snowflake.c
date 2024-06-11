#include <stdio.h>
#include <string.h>
#include "functions.h"

void snowflake(int x, int y, int r, int g, int b, int iteration)
{   
    // Grabbing the hex color value:
    char color[8];
    getHexCode(r, g, b, color);

    // Variables for the positions the snowflake will go to during the animation:
    int xLeft = -x - 120;
    int yDown = 1200 - y;
    int yUp = -y - 120;

    // Printing one snowflake:
    printf("  <g id=\"snowflake\">\n");
    for (int i = 0; i < 6; ++i) {
        printf("    <defs>\n");
        printf("      <path id=\"branch%d\"\n        d=\"M0 0 L0 -90 M0 -20 L20 -34 M0 -20 L-20 -34 M0 -40 L20 -54 M0 -40 L-20 -54 M0 -60 L20 -74 M0 -60 L-20 -74\"\n", iteration);
        printf("        stroke=\"%s\"\n        stroke-width=\"5\"\n      />\n    </defs>\n", color);
        printf("    <use href=\"#branch%d\" transform=\"translate(%d,%d) rotate(%d)\" />\n", iteration, x, y, i * 60);
    }

    // Determining the speed at which it will fall and printing the relevant code:
    if ((iteration % 3) == 0) {
        // Falling fast. 
        printf("    <animateMotion\n                  path=\"M0,0 0,%d %d,%d %d,%d 0,%d 0,0\"\n", yDown, xLeft, yDown, xLeft, yUp, yUp);
        printf("                  begin=\"0s\" dur=\"12s\" repeatCount=\"indefinite\"\n                  />\n  </g>\n");
    } else if ((iteration % 3) == 1) {
        // Falling slowly.
        printf("    <animateMotion\n                  path=\"M0,0 0,%d %d,%d %d,%d 0,%d 0,0\"\n", yDown, xLeft, yDown, xLeft, yUp, yUp);
        printf("                  begin=\"0s\" dur=\"23s\" repeatCount=\"indefinite\"\n                  />\n  </g>\n");
    } else {
        // Falling at a normal speed.
        printf("    <animateMotion\n                  path=\"M0,0 0,%d %d,%d %d,%d 0,%d 0,0\"\n", yDown, xLeft, yDown, xLeft, yUp, yUp);
        printf("                  begin=\"0s\" dur=\"15s\" repeatCount=\"indefinite\"\n                  />\n  </g>\n");
    }
}