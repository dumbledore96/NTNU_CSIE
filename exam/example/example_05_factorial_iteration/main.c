#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    printf("Please enter an integer: ");

    int32_t     number = 1;
    uint64_t    answer = 1;

    scanf( "%d", &number );

    for( int32_t i = number ; i >= 1; i-- )
    {
        answer *= i;
    }

    printf( "%d! = %lu\n", number, answer );

    return 0;
}
