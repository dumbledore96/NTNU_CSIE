#include <stdio.h>
#include <stdint.h>

int main(){
    uint32_t decimal = 0;

    printf("Please enter an unsigned 16-bits number: ");
    int32_t result = scanf("%d", &decimal);

    if(!result){
        printf("Error, Input number is not allowded.");
        return 0;
    }
    if(decimal > 65535){
        printf("Error, Input number is not allowded.");
        return 0;
    }

    printf("Before Flip:\n");
    printf("%d_10 = %o_8\n", decimal, decimal);

    uint32_t octal = 0;
    if(decimal > 0){
        octal += decimal%8;
        decimal /= 8;
    } 
    if(decimal > 0){
        octal *= 10;
        octal += decimal%8;
        decimal /= 8;
    } 
    if(decimal > 0){
        octal *= 10;
        octal += decimal%8;
        decimal /= 8;
    } 
    if(decimal > 0){
        octal *= 10;
        octal += decimal%8;
        decimal /= 8;
    } 
    if(decimal > 0){
        octal *= 10;
        octal += decimal%8;
        decimal /= 8;
    } 
    if(decimal > 0){
        octal *= 10;
        octal += decimal%8;
        decimal /= 8;
    } 

    printf("After Flip:\n");
    printf("%d_8 = ", octal);

    decimal = 0;
    uint32_t temp = 1;

    if(octal > 0){
        decimal += (octal%10)*temp;
        octal /= 10;
        temp *= 8;
    } 
    //printf("%d\n", decimal);
    if(octal > 0){
        decimal += (octal%10)*temp;
        octal /= 10;
        temp *= 8;
    } 
    //printf("%d\n", decimal);
    if(octal > 0){
        decimal += (octal%10)*temp;
        octal /= 10;
        temp *= 8;
    } 
    // printf("%d\n", decimal);
    if(octal > 0){
        decimal += (octal%10)*temp;
        octal /= 10;
        temp *= 8;
    } 
    // printf("%d\n", decimal);
    if(octal > 0){
        decimal += (octal%10)*temp;
        octal /= 10;
        temp *= 8;
    } 
    // printf("%d\n", decimal);
    if(octal > 0){
        decimal += (octal%10)*temp;
        octal /= 10;
        temp *= 8;
    } 
    printf("%d_10\n", decimal);

    return 0;
}