#include <stdio.h>
#include <stdint.h>

int main() {
    int32_t a1 = 0;
    int32_t a2 = 0;
    int32_t b = 0;
    int32_t sum = 0;

    printf("Please enter the first  operand: ");
    scanf("%dx%d", &a1, &a2);

    printf("Please enter the second operand: ");
    scanf("\ny%dz", &b);

    printf("Please enter the sum           : ");
    scanf("%d", &sum);

    // printf("%d %d %d %d\n", a1, a2, b, sum);
    if(a1/10 || a2/10 || b/10){
        printf("Error: The input number is not allowed.\n");
        return 0;
    }
    if(sum==0){
        printf("Error: The input number is not allowed.\n");
        return 0;
    }

    int32_t first_n = a1*100 + b*10 + a2;
    sum  = sum - first_n;

    if(sum <= 0){
        printf("Error: The input number is not allowed.\n");
        return 0;
    }

    printf("Ans: x = %d, y = %d, z = %d\n", (sum/10) % 10, sum/100, sum%10);
    
    return 0;
}