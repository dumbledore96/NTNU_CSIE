#include<stdio.h>
#include<stdint.h>

int main(){
    int32_t a = 100;
    uint32_t b = (uint32_t)a;
    printf(" int32_t %10d converting to uint32_t is %10u\n", a, b);
    b = 100;
    a = (int32_t)b;
    printf("uint32_t %10u converting to  int32_t is %10d\n", b, a);
    a = -1;
    b = (int32_t)a;
    printf(" int32_t %10d converting to uint32_t is %10u\n", a, b);
}