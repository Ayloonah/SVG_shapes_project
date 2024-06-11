#include <stdio.h>
#include <string.h>
#include "functions.h"

void beginHtmlSVG(int wide, int high, char* backColor)
{
    printf("<!DOCTYPE html>\n");
    printf("<html>\n");
    printf("<body>\n");
    printf("<svg height='%d' width='%d' style='stroke-width: 0px; background-color: %s;'>\n",
        high, wide, backColor);
}

void endHtmlSVG()
{
    printf("</svg>\n");
    printf("</body>\n");
    printf("</html>\n");
}