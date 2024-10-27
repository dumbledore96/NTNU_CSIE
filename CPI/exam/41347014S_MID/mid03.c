#include <stdio.h>
#include <stdint.h>
#include "parallelogram.h"

int main(){
    int32_t x1=0, y1=1;
    int32_t x2=0, y2=1;
    int32_t x3=0, y3=1;
    // Setup three points for a parallelogram.
    // Success : return 1; Fail: return 0
    printf("x1: %d\n", setP1(1, 1));
    printf("x2: %d\n", setP2(2, 2));
    printf("x3: %d\n", setP3(3, 0));
    printf("check: %d\n", check());
    printf("getPerimeter: %lf\n", getPerimeter());
    printf("getArea: %lf\n", getArea());
    printf("getP1Degree: %lf\n", getP1Degree());
    return 0;
}