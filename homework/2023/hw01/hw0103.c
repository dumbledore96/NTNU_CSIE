#include<stdio.h>
#include<stdint.h>

int main(){
    int32_t ax = 0, ay = 0;
    int32_t bx = 0, by = 0;

    printf("Please enter the point A (x,y): ");
    scanf("%d,%d", &ax, &ay);
    if(ax==0 && ay==0){
        printf("Error: Area 0.\n");
        return 0;
    }
    printf("Please enter the point B (x,y): ");
    scanf("%d,%d", &bx, &by);
    if(bx==0 && by==0){
        printf("Error: Area 0.\n");
        return 0;
    }
    
    if(ax==bx || ay==by){
        printf("Error, No area exists.\n");
        return 0;
    }
    float slope = ((float)ax - (float)bx) / ((float)ay - (float)by);
    float intercept1 = (float)ay - (float)ax * slope; 
    float intercept2 = -(intercept1 / slope);
    printf("Area: %.2f\n", intercept1 * intercept2 / 2);
}