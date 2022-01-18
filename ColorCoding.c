#include <stdio.h>
#include "ColorCoding.h"

const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};
const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

int numberOfMajorColors =
    sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors =
    sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

void ColorPairString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorPair(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumber(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}

int GetReferenceManual(){
    printf("\nColor Pair Manual:\nPairNo. Maj.Color Min.Color\n");
    for (int pairNumber=1; pairNumber<MAX_COLORPAIR; pairNumber++)
    {
         ColorPair colorPair = GetColorPair(pairNumber);
         char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
         ColorPairString(&colorPair, colorPairNames);
         printf("%d\t%s\n", pairNumber, colorPairNames);
    }
    return TRUE;
}
