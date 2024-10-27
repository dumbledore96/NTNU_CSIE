#include <stdio.h>
#include <math.h>

int main()
{
    double num = 0.0;
    printf( "Please enter a floating number: " );
    scanf( "%lf", &num );

    printf( "sqrt(%f) = %f\n", num, sqrt( num ) );

    return 0;
}
