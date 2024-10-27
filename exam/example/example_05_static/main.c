#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void get_static_variable( void );

int main()
{
    for( int32_t i = 0 ; i < 10 ; i++ )
    {
        get_static_variable();
    }

    return 0;
}

void get_static_variable( void )
{
    static int32_t counter = 0;

    counter++;

    printf( "counter = %d\n" ,  counter );

    return;
}
