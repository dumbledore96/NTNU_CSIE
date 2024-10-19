#include<stdio.h>
#include<stdint.h>

int main(){
    float a = 2.5;
    int32_t b = (int32_t)a;
    printf("  float %20f converting to int32_t is %20d\n", a, b);
    a = 10000000000.0;
    b = (int32_t)a;
    printf("  float %20f converting to int32_t is %20d\n", a, b);
    b = 100;
    a = (float)b;
    printf("int32_t %20d converting to   float is %20f\n", b, a);
    b = 16777217;
    a = (float)b;
    printf("int32_t %20d converting to   float is %20f\n", b, a);
}