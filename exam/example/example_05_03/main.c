// Function example

#include <stdio.h>
#include <stdint.h>
#include "mymax.h"

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

