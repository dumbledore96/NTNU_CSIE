#include<stdio.h>
#include<stdint.h>

int main(){
    double ux = 0, uy = 0, x = 0, y = 0, uxy = 0, ux2 = 0;
    int32_t n = 0;
    do{
        printf("Please enter the year: ");
        scanf("%lf", &x);
        if(x == -1){
            break;
        }
        printf("Temperature: ");
        scanf("%lf", &y);
        ux += x;
        uy += y;
        ux2 += x*x;
        uxy += x*y;
        n++;
    } while(x != -1);
    printf("Please enter the prediction year: ");
    scanf("%lf", &x);
    ux /= n;
    uy /= n;
    int32_t m = (uxy - n*ux*uy) / (ux2 - n*ux*ux);
    y = (x - ux) * m + uy;
    printf("Temperature: %.1f\n", y);

    return 0;
}