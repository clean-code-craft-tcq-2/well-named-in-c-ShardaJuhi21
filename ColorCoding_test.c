#include <stdio.h>
#include <assert.h>
#include "ColorCoding.h"

void testGetColorPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorPair(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testGetPairNumber(
    enum MajorColor major,
    enum MinorColor minor,
    int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumber(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

void testGetReferenceManual()
{
     printf("Color Pair Manual:\n PairNumber MajorColor MinorColor\n");
     for (int pairNumber=0; pairNumber<MAX_COLORPAIR; pairNumber++)
     {
         GetReferenceManual(pairNumber);
         char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
         ColorPairString(&colorPair, colorPairNames);
         printf("%d %s\n", pairNumber, colorPairNames); 
     }
}
