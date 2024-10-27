// Function example

#include <stdio.h>
#include <stdint.h>

int32_t maximum( int32_t x, int32_t y, int32_t z ); // Function Prototype

// Main Function
int main()
{
    int32_t number1 = 0;
    int32_t number2 = 0;
    int32_t number3 = 0;

    printf( "Please enter three integers: " );
    scanf( "%d %d %d", &number1, &number2, &number3 );

    printf( "Max Value is %d\n", maximum( number1, number2, number3 ) );

    return 0;
}

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
