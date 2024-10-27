// Roll a Die

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main()
{
    srand( time(0) );

    for( int32_t i = 1 ; i <= 36 ; i++ )
    {
        printf( "%4d ", 1 + rand() % 6 );

        if( i % 6 == 0 )
        {
            printf( "\n" );
        }
    }

    return 0;
}
