#include <stdio.h>
#include <string.h>
#include "functions.h"

void getHexCode(int r, int g, int b, char *hexCode)
{
    char red[3], green[3], blue[3];

    deciToHex(r, red);
    deciToHex(g, green);
    deciToHex(b, blue);

    sprintf(hexCode, "#%s%s%s", red, green, blue);
}

void deciToHex(int color, char* hex)
{
    const char *hexDigits = "0123456789ABCDEF";
    
    hex[0] = hexDigits[(color / 16) % 16];
    hex[1] = hexDigits[color % 16];
    hex[2] = '\0';
}