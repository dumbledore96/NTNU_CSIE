// Scope

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t x = 1; // Global Variable

void get_local_variable( void );
void get_global_variable( void );

int main()
{
    printf( "x = %d\n", x );

    int32_t x = 5;  // Local Variable

    printf( "x = %d\n", x );

    {
        int32_t x = 25;  // Local Variable

        printf( "x = %d\n", x );
    }

    get_local_variable();
    get_global_variable();

    return 0;
}

void get_local_variable( void )
{
    int32_t x = 100;  // Local Variable

    printf( "x = %d\n", x );

    return;
}

void get_global_variable( void )
{
    printf( "x = %d\n", x );

    return;
}
