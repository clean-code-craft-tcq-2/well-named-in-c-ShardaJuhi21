#include <stdio.h>
#include "ColorCoding.h"

int main() {
    testGetColorPair(4, WHITE, BROWN);
    testGetColorPair(5, WHITE, SLATE);

    testGetPairNumber(BLACK, ORANGE, 12);
    testGetPairNumber(VIOLET, SLATE, 25);
    
    testGetReferenceManual();

    return 0;
}
