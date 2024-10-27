#include <stdio.h>
#include <stdint.h>

void add_one( int32_t x );

int main()
{
    int32_t number = 10;

    add_one( number );

    printf( "Number is %d\n", number );

    return 0;
}

void add_one( int32_t x )
{
    x += 1;
    return;
}
