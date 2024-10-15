#include<stdio.h>
#include<stdint.h>

int main(){
    double ux = 0, uy = 0, x = 0, y = 0, uxy = 0, ux2 = 0;
    int32_t n = 0;
    uint8_t temp;
    while(1){
        printf("Please enter the year: ");
        while(scanf("%lf", &x) != 1){
            scanf("%c",&temp);
            printf("Error, please enter the year again: ");
        }
        if(x == -1){
            break;
        }
        printf("Temperature: ");
        while(scanf("%lf", &y) != 1){
            scanf("%c",&temp);
            printf("Error, please enter temperature again: ");
        }
        ux += x;
        uy += y;
        ux2 += x*x;
        uxy += x*y;
        n++;
    }
    printf("Please enter the prediction year: ");
    while(scanf("%lf", &x) != 1){
        scanf("%c",&temp);
        printf("Error, please enter the prediction year again: ");
    }
    ux /= n;
    uy /= n;
    double m = (uxy - n*ux*uy) / (ux2 - n*ux*ux);
    y = (x - ux) * m + uy;
    // printf("m: %.1f\n", m);
    printf("Temperature: %f\n", y);

    return 0;
}