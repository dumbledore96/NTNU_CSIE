#include<stdio.h>

int main(){
    double a = 1.5;
    float b = (float)a;
    printf("double %f converting to  float is %f\n", a, b);
    a = 0.3;
    b = (float)a;
    printf("double %.22f converting to  float is %.20f\n", a, b);
    a = 1e308;
    b = (float)a;
    printf("double %f converting to  float is %f\n", a, b);
}