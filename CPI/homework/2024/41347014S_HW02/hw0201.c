#include<stdio.h>
#include<stdint.h>

int main(){
    int32_t n = 0;
    printf("Please enter n (16-bits unsigned): ");
    if(scanf("%d", &n) == 0 || n <= 0){
        printf("Invalid input\n");
        return 0;
    }
    double a = 1, b = 1;
    for(int32_t i = 1 ; i <= n ; i++){
        double approach = a / b;
        printf("n = %2d: %.20f (%.20f)\n", i, approach, 1.61803398874989484820 - approach);
        double temp = a;
        a += b;
        b = temp;
    }

    return 0;
}