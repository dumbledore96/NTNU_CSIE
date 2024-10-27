#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t    factorial( int32_t number )
{
    if( 2 == number || 1 == number )
    {
        return ( uint64_t ) number;
    }

    return number * factorial( number - 1 );
}

int main()
{
    printf("Please enter an integer: ");

    int32_t     number = 1;
    uint64_t    answer = 1;

    scanf( "%d", &number );

    answer = factorial( number );

    printf( "%d! = %lu\n", number, answer );

    return 0;
}
