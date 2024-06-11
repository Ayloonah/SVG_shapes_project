#include <stdio.h>
#include <string.h>
#include "functions.h"

void cube(int originX, int originY, int width, int height, int depth, int r, int g, int b, float shadowAmount)
{
    // Declaring the variables, starting with a struct for that stores the cubes' x and y positions:
    typedef struct {
        int X;
        int Y;
    } CubePosition;

    // Character arrays for the coordinates and color values:
    char A[20], B[20], C[20], D[20], E[20], F[20], G[20], originalColor[8], shadedColor[8];

    // Declaring and initializing an integer array to store the color values for the shaded side of the cube:
    int darkerColor[3] = { r * shadowAmount, g * shadowAmount, b * shadowAmount };

    // Clamping the shadowAmount value between 0 and 1:
    shadowAmount = shadowAmount < 0 ? 0 : shadowAmount > 1 ? 1 : shadowAmount;
    // Converting both to HEX codes: 
    getHexCode(r, g, b, originalColor);
    getHexCode(darkerColor[0], darkerColor[1], darkerColor[2], shadedColor);

    // Initializing various CubePositions variables for offsets: 
    CubePosition adjustedA = { originX, originY };
    CubePosition adjustedB = { width + originX, originY };
    CubePosition adjustedC = { width + originX, height + originY };
    CubePosition adjustedD = { originX, height + originY };
    CubePosition adjustedE = { originX + (depth * 0.5), originY - (depth * 0.5) };
    CubePosition adjustedF = { originX + width + (depth * 0.5), originY - (depth * 0.5) };
    CubePosition adjustedG = { originX + width + (depth * 0.5), originY - (depth * 0.25) + (height * 0.5) };

    // Formatting the CubePositions structs as strings:
    sprintf(A, "%d,%d", adjustedA.X, adjustedA.Y);
    sprintf(B, "%d,%d", adjustedB.X, adjustedB.Y);
    sprintf(C, "%d,%d", adjustedC.X, adjustedC.Y);
    sprintf(D, "%d,%d", adjustedD.X, adjustedD.Y);
    sprintf(E, "%d,%d", adjustedE.X, adjustedE.Y);
    sprintf(F, "%d,%d", adjustedF.X, adjustedF.Y);
    sprintf(G, "%d,%d", adjustedG.X, adjustedG.Y);

    // A B C D - Front face
    printf("  <polygon points = '%s %s %s %s' style = 'fill:%s;stroke:white;stroke-width:2'/>\n"
        // A E F B - Top face
        "  <polygon points = '%s %s %s %s' style = 'fill:%s;stroke:white;stroke-width:2'/>\n"
        // B F G C - Top face
        "  <polygon points = '%s %s %s %s' style = 'fill:%s;stroke:white;stroke-width:2'/>\n"
        , A, B, C, D, originalColor, A, E, F, B, originalColor, B, F, G, C, shadedColor);
}