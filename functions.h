#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* Converts a decimal number to hexadecimal number. 
    args: 
        int color: An integer between 0 and 255 representing the color value for R, G, or B.
        char* hex: A character array that will retain the hex value corresponding to the decimal color value.
    Nothing is returned aside from the updated array. */
void deciToHex(int color, char* hex);

/* Converts RGB color values to a HEX code.
    args:
        int r: An integer between 0 and 255 representing the red color value.
        int g: An integer between 0 and 255 representing the green color value.
        int b: An integer between 0 and 255 representing the blue color value.
        char *hexCode: A character array that will retain the full hex value corresponding to the RGB color value. */
void getHexCode(int r, int g, int b, char *hexCode);

/* Prints the beginning of the SVG file code.
    args:
        int wide: An integer that determines how wide the canvas is. 
        int high: An integer that determines the height of the canvas.
        char* backColor: A character array that contains the color's hex code.
    Nothing is returned aside from the updated array. */
void beginHtmlSVG(int wide, int high, char* backColor);

/* Prints the ending of the SVG file code.
    There are no arguments, and nothing is returned aside from the updated array. */
void endHtmlSVG();

/* Creates cubes on the canvas.
    args: 
        int originX: An integer representing the x position from where the initial cube starts.
        int originY: An integer representing the y position from where the initial cube starts.
        int width: An integer representing the cube's width.
        int height: An integer representing the cube's height.
        int depth: An integer representing the cube's depth.
        int r: An integer between 0 and 255 representing the red color value.
        int g: An integer between 0 and 255 representing the green color value.
        int b: An integer between 0 and 255 representing the blue color value.
        float shadowAmount: An integer between 0 and 1 representing the amount the side face is shaded.
    Nothing is returned. */
void cube(int originX, int originY, int width, int height, int depth, int r, int g, int b, float shadowAmount);

/* Creates snowflakes which fall down at varying speeds based on the amount of iterations.
    Args: 
        x: Starting x position.
        y: Starting y position.
        r: Red value.
        g: Green value.
        b: Blue value.
        iteration: The number of loops you have gone through, aka snowflakes you have made.
    Nothing is returned. */
void snowflake(int x, int y, int r, int g, int b, int iteration);

#endif