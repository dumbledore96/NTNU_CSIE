#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t     oldStudent01 = 60, newStudent01 = 0;
    int32_t     oldStudent02 = 97, newStudent02 = 0;
    int32_t     oldStudent03 = 86, newStudent03 = 0;
    int32_t     oldStudent04 = 72, newStudent04 = 0;
    int32_t     oldStudent05 = 98, newStudent05 = 0;

    newStudent01 = oldStudent01 * 0.65 + 40;

    if( newStudent01 > 100 )
    {
        newStudent01 = 100;
    }

    printf( "New Grade: %d\n", newStudent01 );

    newStudent02 = oldStudent02 * 0.65 + 40;

    if( newStudent02 > 100 )
    {
        newStudent02 = 100;
    }

    printf( "New Grade: %d\n", newStudent02 );

    newStudent03 = oldStudent03 * 0.65 + 40;

    if( newStudent03 > 100 )
    {
        newStudent03 = 100;
    }

    printf( "New Grade: %d\n", newStudent03 );

    newStudent04 = oldStudent04 * 0.65 + 40;

    if( newStudent04 > 100 )
    {
        newStudent04 = 100;
    }

    printf( "New Grade: %d\n", newStudent04 );

    newStudent05 = oldStudent05 * 0.65 + 40;

    if( newStudent05 > 100 )
    {
        newStudent05 = 100;
    }

    printf( "New Grade: %d\n", newStudent05 );

    return 0;
}
