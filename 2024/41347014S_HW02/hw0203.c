#include<stdio.h>
#include<stdint.h>

int main(){
    double ux = 0, uy = 0, x = 0, y = 0, uxy = 0, ux2 = 0;
    int64_t n = 0;
    uint8_t temp;
    while(1){
        printf("Please enter the year: ");
        if(scanf("%lf", &x) != 1){
            printf("Error");
            return 0;
        }
        if(x == -1){
            break;
        }
        printf("Temperature: ");
        if(scanf("%lf", &y) != 1){
            printf("Error");
            return 0;
        }
        ux += x;
        uy += y;
        ux2 += x*x;
        uxy += x*y;
        n++;
    }
    printf("Please enter the prediction year: ");
    if(scanf("%lf", &x) != 1){
        printf("Error");
        return 0;
    }
    ux /= n;
    uy /= n;
    double m = (uxy - n*ux*uy) / (ux2 - n*ux*ux);
    y = (x - ux) * m + uy;
    // printf("m: %.1f\n", m);
    printf("Temperature: %f\n", y);

    return 0;
}