#include "mymax.h"

// Real Function Definition

int32_t maximum( int32_t x, int32_t y, int32_t z )
{
    int32_t max = x;

    if( y > max )
    {
        max = y;
    }

    if( z > max )
    {
        max = z;
    }

    return max;
}
